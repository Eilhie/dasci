#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);
        int a[n+1], s[n+1];
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            s[i] = s[i-1] + a[i];
        }

        int q;
        scanf("%d", &q);
        printf("Case #%d:\n", t);
        for (int i = 1; i <= q; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", s[r] - s[l-1]);
        }
    }

    return 0;
}
