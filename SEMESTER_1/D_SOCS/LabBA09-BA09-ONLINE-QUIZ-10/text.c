#include <stdio.h>
#include <string.h>

int main(){

    int testCases;
    scanf("%d", &testCases); getchar();
    for(int i = 0; i < testCases; i++){
        char string[1001], str[1001] = "";
        scanf("%[^\n]", string); getchar();
        int len = strlen(string);
        for(int j = 0; j < len; j++){
            if(!(string[j] == 'a' || string[j] == 'A' || string[j] == 'i' || string[j] == 'I' || string[j] == 'u' || string[j] == 'U' || string[j] == 'e' || string[j] == 'E' || string[j] == 'o' || string[j] == 'O')){
                strncat(str, &string[j], 1);
            }
            
        }

        printf("Case #%d: %s\n", i + 1, str);

    }

    return 0;
}