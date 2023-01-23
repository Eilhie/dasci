#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        int n, a[105], acute = 0, right = 0, obtuse = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    int max = a[i], min1 = a[j], min2 = a[k];
                    if (a[j] > max) {
                        max = a[j];
                        min1 = a[i];
                        min2 = a[k];
                    }
                    if (a[k] > max) {
                        max = a[k];
                        min1 = a[i];
                        min2 = a[j];
                    }
                    if (min1 + min2 <= max) {
                        obtuse++;
                    } else if (pow(min1, 2) + pow(min2, 2) == pow(max, 2)) {
                        right++;
                    } else {
                        acute++;
                    }
                }
            }
        }
        printf("Case #%d: %d %d %d\n", cas, acute, right, obtuse);
    }
    return 0;
}
