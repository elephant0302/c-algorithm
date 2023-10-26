#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> a; // ��ü ����
	vector<int> b; // ���� ���ϱ� ���� ���� ����
	vector<int> tmp1; // b�� 1�� �� �� ��ġ�� �ش��ϴ� a �� �����ϴ� ����
	vector<int> tmp2; // b�� 0�� �� �� ��ġ�� �ش��ϴ� b �� �����ϴ� ����
	vector<int> tmp3; // ������ ������ ����� ���� ����

	for (int i = 0; i < n; i++) {
		a.push_back(i + 1);	
	}
	
	for (int i = 0; i < k; i++) {
		b.push_back(1);
	}
	for (int i = 0; i < n-k; i++) {
		b.push_back(0);
	}
	if (k == 0) {
		std::cout << "00";
	}
	do {
		for (int i = 0; i < a.size(); i++) {
			if (b[i] == 1 ) {
				std::cout << a[i];
				tmp1.push_back(a[i]);
			}
			else {
				tmp2.push_back(a[i]);
			}
		}
		for (int j = 0; j < n-k; j++) {
			std::cout << " ";
			for (int i = 0; i < tmp1.size(); i++) {
				tmp3.push_back(tmp1[i]);
			}

			tmp3.push_back(tmp2[j]);
			sort(tmp3.begin(), tmp3.end());

			for (int i = 0; i < tmp3.size(); i++) {
				std::cout << setw(2) << setfill('0') << tmp3[i];
			}

			tmp3.clear();
		}
		std::cout << "\n";
		tmp1.clear();
		tmp2.clear();
	} while (prev_permutation(b.begin(), b.end()));
	
	return 0;
}
