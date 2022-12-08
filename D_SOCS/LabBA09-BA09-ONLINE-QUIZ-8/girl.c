#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        char *s = (char *) malloc (sizeof(char) * (int) pow(10, 6)); 
        scanf("%s", s);
        int alpha[26] = {0};
        int result = 0;
        for(int i = 0; i < strlen(s); i++){
            alpha[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(alpha[i] > 0) result++;
        }
        if(result % 2 == 0)
            printf("Case #%d: Yay\n", i + 1);
        else 
            printf("Case #%d: Ewwww\n", i + 1);
    }

    return 0;
}

// int main() {
//     int t, counter;
//     bool distinct[27];
//     scanf("%d", &t);
//     char username[t+1][120000];
//     for (int i = 1; i <= t; i++) {
//         for (int j = 0; j < 26; j++) {
//             distinct[j] = false;
//         }
//         scanf("%s", username[i-1]);
//         for (int j = 0; username[i-1][j] != '\0'; j++) {
//             distinct[username[i-1][j]-'a'] = true;
//         }
//         counter = 0;
//         for (int j = 0; j < 26; j++) {
//             if (distinct[j] == true) counter++;
//         }
//         printf("Case #%d: %s\n", i, (counter%2 == 0)?"Yay":"Ewwww");
//     }
//     return 0;
// }