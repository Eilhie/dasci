#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        int n, count = 0;
        scanf("%d", &n);
        int limit = sqrt(n);
        for (int i = 1; i <= limit; i++) {
            if (n % i == 0) {
                count++;
                if (i != n/i) {
                    count++;
                }
            }
        }
        printf("Case #%d: %d\n", cas, count);
    }
    return 0;
}
