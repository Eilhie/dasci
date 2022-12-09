#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        char s[120000]; 
        scanf("%s", s);
        int alpha[26] = {0};
        int result = 0;
        for(int j = 0; s[j] != '\0'; j++){
            alpha[s[j] - 'a'] = 1;
        }
        for(int j = 0; j < 26; j++){
            if(alpha[j] == 1) result++;
        }
        printf("Case #%d: %s\n", i + 1, (result%2 == 0)?"Yay":"Ewwww");
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