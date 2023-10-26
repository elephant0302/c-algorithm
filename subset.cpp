#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> a; // 전체 수열
	vector<int> b; // 조합 구하기 위한 보조 수열
	vector<int> tmp1; // b가 1일 때 그 위치에 해당하는 a 값 저장하는 벡터
	vector<int> tmp2; // b가 0일 때 그 위치에 해당하는 b 값 저장하는 벡터
	vector<int> tmp3; // 사전식 순서를 만들기 위한 벡터

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
