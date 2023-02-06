#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int testCases;
    scanf("%d", &testCases); getchar();
    for(int i = 0; i < testCases; i++){
        char string[101];
        gets(string);
        int flag = 0;
        int len = strlen(string);
        for(int i = 0; i < len; i++){
            if(string[i] == ' '){
                
                for(int j = i; j < len; j++){
                    string[j] = string[j + 1];
                }
                len--;
            }
        }
        // printf("%s\n", string);
        for(int j = 0; j < len / 2; j++){
            if(tolower(string[j]) != tolower(string[len - j - 1])){
                flag = 1;
            }
        }
        if(flag == 1){
            printf("Case #%d: false\n", i + 1);
        } else printf("Case #%d: true\n", i + 1);
        

    }

    return 0;
}