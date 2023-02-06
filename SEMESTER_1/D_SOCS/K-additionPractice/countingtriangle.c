#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);
        int sticks[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &sticks[i]);
        }

        int acute = 0, right = 0, obtuse = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // check if the combination of sticks forms a triangle
                    if (sticks[i] + sticks[j] > sticks[k] && sticks[j] + sticks[k] > sticks[i] && sticks[k] + sticks[i] > sticks[j]) {
                        // check if the triangle is acute, right, or obtuse
                        if ((sticks[i] * sticks[i] + sticks[j] * sticks[j]) > sticks[k] * sticks[k]) {
                            acute++;
                        }
                        else if ((sticks[i] * sticks[i] + sticks[j] * sticks[j]) == sticks[k] * sticks[k]) {
                            right++;
                        }
                        else if ((sticks[i] * sticks[i] + sticks[j] * sticks[j]) < sticks[k] * sticks[k]) {
                            obtuse++;
                        }
                    }
                }
            }
        }
        // output the results for this test case
        printf("Case #%d: %d %d %d\n", t, acute, right, obtuse);
    }
    return 0;
}
