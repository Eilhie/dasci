#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* find_password(char** names, int n) {
    int len[n];
    for(int i=0;i<n;i++) len[i]=strlen(names[i]);
    int i = 0;
    int j = 0;
    while (i < len[0] && j < len[0]) {
        int k = 0;
        while (k < n && i + k < len[k] && names[k][i] == names[0][i + k]) k++;
        if (k == n) {
            i++;
        } else {
            break;
        }
    }
    while (j < len[0]) {
        int k = 0;
        while (k < n && j + k < len[k] && names[k][len[k] - 1 - j] == names[0][len[0] - 1 - j]) k++;
        if (k == n) {
            j++;
        } else {
            break;
        }
    }
    int len_password = len[0] - i - j;
    char password[len_password + 1];
    for (int k = i; k < len[0] - j; k++) {
        password[k - i] = names[0][k];
    }
    password[len_password] = '\0';
    return password;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);
        char **names;
        names = malloc(n*sizeof(char*));
        for (int i = 0; i < n; i++) {
            names[i] = malloc(1001*sizeof(char));
            scanf("%s", names[i]);
        }
        
        printf("%s\n", find_password(names, n));
    }
    return 0;
}

