#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ispalindrome(char *string){
    
    for(int j = 0; j < strlen(string) / 2; j++){
        if(tolower(string[j]) != tolower(string[strlen(string) - j - 1])){
            return 0;
        }
    }
    return 1;
}

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        char string[1010];
        scanf("%s", string);
        int res = ispalindrome(string);
        if(res != 0) printf("Case #%d: yes\n", i + 1);
        else printf("Case #%d: no\n", i + 1);
    }

    return 0;
}