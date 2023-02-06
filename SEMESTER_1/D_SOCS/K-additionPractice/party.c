#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *inputFile = fopen("testdata.in", "r");
    int T;
    fscanf(inputFile, "%d\n", &T);
    for (int i = 1; i <= T; i++) {
        char str[10101];
        fscanf(inputFile, "%s\n", str);
        int sum = 0;
        for (int j = 0; j < strlen(str); j++) {
            sum += str[j]-'0';
        }
        int lastDigit = str[strlen(str) - 1] - '0';
        if (sum % 3 == 0 && lastDigit % 2 == 0) {
            printf("Case #%d: YES\n", i);
        } else {
            printf("Case #%d: NO\n", i);
        }
    }
    fclose(inputFile);
    return 0;
}