#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int testCases;
    scanf("%d", &testCases); getchar;
    for(int i = 0; i < testCases; i++){
        char string[510];
        scanf("%s", string);
        int flag = 0;
        printf("Case #%d: ", i + 1);
        for(int j = 0; j < strlen(string) / 2; j++){
            if(tolower(string[j]) != tolower(string[strlen(string) - j - 1])){
                flag = 1;
            }
        }
        if(flag > 0){
            printf("Nah, it\'s not a palindrome\n");
        } else {
            printf("Yay, it\'s a palindrome\n");
        }
    }

    return 0;
}