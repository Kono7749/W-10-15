#include <stdio.h>
#include <stdlib.h>

int* KnapsackDP(int *w, int *v, int n, int Wx) {
    int i, j;

    int dp[n+1][Wx+1];

    for(i = 0; i <= n; i++)
        for(j = 0; j <= Wx; j++)
            dp[i][j] = 0;

    for(i = 1; i <= n; i++) {
        for(j = 0; j <= Wx; j++) {
            if(w[i-1] <= j) {
                int include = v[i-1] + dp[i-1][j - w[i-1]];
                int exclude = dp[i-1][j];
                dp[i][j] = (include > exclude) ? include : exclude;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int *x = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        x[i] = 0;

    j = Wx;
    for(i = n; i > 0; i--) {
        if(dp[i][j] != dp[i-1][j]) {
            x[i-1] = 1;
            j -= w[i-1];
        }
    }

    return x;
}

int main() {
    int n = 5, Wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x = KnapsackDP(w, v, n, Wx);

    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    free(x);
    return 0;
}