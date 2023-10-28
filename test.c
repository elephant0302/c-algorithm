#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int A[200001], B[101];
int comparison[200001][101] = { 0 };

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &B[i]);
    }

    for (int i = 0; i <= n; i++) {
        comparison[i][0] = 1; 
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i] == B[j]) {
                comparison[i][j] = (comparison[i - 1][j - 1] + comparison[i - 1][j]) % 20221022;
            }
            else {
                comparison[i][j] = comparison[i - 1][j];
            }
        }
    }
    printf("%d\n", comparison[n][m]);
    return 0;
}