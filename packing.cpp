#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    vector<int> d(n);
    int total = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        d[i] = abs(a - b);
        total += d[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(total + 1, false));
    dp[0][0] = true; 

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= total; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= d[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - d[i - 1]];
            }
        }
    }

    int answer = total;
    for (int j = 0; j <= total; ++j) {
        if (dp[n][j]) {
            answer = min(answer, abs(total - 2 * j));
        }
    }

    cout << answer;
    return 0;
}
