#include <stdio.h>
#include <string.h>

void fibWord(int n, char a, char b, char* Sn) {
    char Sn_1 = a;
    char Sn_2 = b;
    char tmp;
    for (int i = 2; i <= n; i++) {
        tmp = Sn_2;
        Sn_2 = Sn_2 + Sn_1;
        Sn_1 = tmp;
    }
    strcpy(Sn, &Sn_2);
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    for (int i = 0; i < testCases; i++) {
        int n;
        char a, b;
        scanf("%d %c %c", &n, &a, &b);
        char Sn[n + 1];
        fibWord(n, a, b, Sn);
        printf("Case #%d: %s\n", i + 1, Sn);
    }

    return 0;
}
