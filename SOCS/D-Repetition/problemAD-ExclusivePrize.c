#include <stdio.h>
int main() {
    int testCases ,n,prize[1005];
    int result = 0;
    for (int i = 0; i <= 1005; i++) {
        prize[i] = 0;
    }
    scanf("%d", &testCases);
    for (int i = 0; i < testCases; i++) {
        scanf("%d", &n);
        prize[n]++;
        if(prize[n] > result) {
            result = prize[n];
        }
    }
    printf("%d\n", result);
    return 0;
}