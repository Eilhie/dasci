#include <stdio.h>

#define MAX_STICKS 51

int main(int argc, char **argv) {
    int n, i, j;
    long long sticks[MAX_STICKS];

    // Read in the number of sticks
    FILE *fp = fopen("testdata.in", "r");
    fscanf(fp, "%d\n", &n);

    // Read in the length of each stick
    for (i = 0; i < n; i++) {
        fscanf(fp, "%lld\n", &sticks[i]);
    }

    // Sort the sticks in non-decreasing order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (sticks[i] < sticks[j]) {
                long long temp = sticks[i];
                sticks[i] = sticks[j];
                sticks[j] = temp;
            }
        }
    }

    // Check if Lili can form a triangle with the given set of sticks
    for (i = 0; i < n - 2; i++) {
        for (j = i + 1; j < n - 1; j++) {
            if (sticks[i] < sticks[j] + sticks[j + 1]) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
