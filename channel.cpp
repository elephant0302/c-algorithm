#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	long long n, M;
	cin >> n >> M;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long result = M; 
	long long cnt = 0;
	for (int i = 1; i < n; i++) {
		if (M >= v[i] - v[i - 1]) {
			cnt += v[i] - v[i - 1];
		}
		else {
			result += cnt + M + 1;
			cnt = 0;
		}
	}
	result = result + cnt + 1; 
	cout << result;
}

