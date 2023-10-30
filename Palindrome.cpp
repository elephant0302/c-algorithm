#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<long long> palin;
	for (int i = 1; i <= 9; i++) { 
		palin.push_back(i);
	}
	for (int i = 1; i <= 9; i++) {
		palin.push_back(i * 10 + i);
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			palin.push_back(j * 100 + i * 10 + j);
		}
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			palin.push_back(i * 1000 + j * 100 + j * 10 + i);
		}
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int a = 0; a <= 9; a++) {
				palin.push_back(i * 10000 + j * 1000 + a * 100 + j * 10 + i);
			}
		}
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				palin.push_back(i * 100000 + j * 10000 + k * 1000 + k * 100 + j * 10 + i);
			}
		}
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				for (int l = 0; l <= 9; l++) {
					palin.push_back(i * 1000000 + j * 100000 + k * 10000 + l * 1000 + k * 100 + j * 10 + i);
				}
			}
		}
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				for (int l = 0; l <= 9; l++) {
					palin.push_back(i * 10000000 + j * 1000000 + k * 100000 + l * 10000 + l*1000 + k * 100 + j * 10 + i);
				}
			}
		}
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				for (int l = 0; l <= 9; l++) {
					for (int m = 0; m <= 9; m++) {
						palin.push_back(i * 100000000 + j * 10000000 + k * 1000000 + l * 100000 + m * 10000 + l * 1000 + k * 100 + j * 10 + i);
					}
				}
			}
		}
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				for (int l = 0; l <= 9; l++) {
					for (int m = 0; m <= 9; m++) {
						palin.push_back(i * 1000000000 + j * 100000000 + k * 10000000 + l * 1000000 + m * 100000 + m * 10000 + l * 1000 + k * 100 + j * 10 + i);
					}
				}
			}
		}
	}

	int n;
	cin >> n;	
	int cnt = 0;
	while (true) {
		if (n >= palin[cnt]) {
			cnt++;
		}
		else {
			break;
		}
	}
	cout << cnt << endl;
}