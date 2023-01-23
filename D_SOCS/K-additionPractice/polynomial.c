#include <stdio.h>
#include <math.h>

long long int a[100005], b[100005], c[100005], n[100005];

int main() {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &c[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &n[i]);
    }
    for (int i = 0; i < m; i++) {
        long long int left = 0, right = n[i], ans = 0;
        while (left <= right) {
            long long int mid = (left + right) / 2;
            if (a[i] * mid *mid * mid + b[i] * mid * mid + c[i] * mid <= n[i]) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

