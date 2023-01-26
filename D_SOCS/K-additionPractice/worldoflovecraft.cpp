#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    long long int T;
    scanf("%lld", &T);

    for (long long int t = 1; t <= T; t++) {
        long long int n, k;
        scanf("%lld%lld", &n, &k);
        long long int v[n+1], w[n+1], dp[n+1][k+1];
        for (long long int i = 1; i <= n; i++) {
            scanf("%lld%lld", &v[i], &w[i]);
        }

        for (long long int i = 0; i <= n; i++) {
            for (long long int j = 0; j <= k; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (w[i] <= j) {
                    dp[i][j] = max(v[i] + dp[i-1][j-w[i]], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        printf("Case #%lld: %lld\n", t, dp[n][k]);
    }
    return 0;
}
