#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int testCases;
    scanf("%d", &testCases); getchar();
    for(int i = 0; i < testCases; i++){
        char string[1000];
        scanf("%s", string);
        printf("Case #%d: ", i + 1);
        int len = strlen(string); int temp;
        for (int j = 0; j < len/2; j++){  
            temp = string[j];  
            string[j] = string[len - j - 1];  
            string[len - j - 1] = temp;  
        }  
        for(int j = 0; j < len; j++){
            if(isupper(string[j])){
                string[j] = tolower(string[j]);
            } else {
                string[j] = toupper(string[j]);
            }
        }
        printf("%s\n", string);
    }

    return 0;
}