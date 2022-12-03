#include <stdio.h>
#include <string.h>

int main(){

    int testCases;
    scanf("%d", &testCases); getchar();
    for(int i = 0; i < testCases; i++){
        char string[1010];
        char str[1010];
        scanf("%[^\n]", string);
        getchar();
        strcpy(str, string);
        printf("Case #%d:\n", i+1);
        for(int j = 0; j < strlen(string); j++){	
            if(string[j]>'A' && string[j]<'E') {
                    string[j]='A';
                    str[j] = str[j] - 65;
            } else if(string[j]>'E' && string[j]<'I') {
                    string[j]='E';
                    str[j] = str[j] - 69;
            } else if(string[j]>'I' && string[j]<'O') {
                    string[j]='I';
                    str[j] = str[j] - 73;
            } else if(string[j]>'O' && string[j]<'U') {
                    string[j]='O';
                    str[j] = str[j] - 79;
            } else if(string[j]>'U') {
                string[j] = 'U';
                str[j] = str[j] - 85;
            }

        }
        printf("%s\n", string);
        for (int j = 0; j < strlen(str); j++) {
            if(str[j] == 'A' || str[j] == 'I' || str[j] == 'U' || str[j] == 'E' || str[j] == 'O'){
                printf("0");
            } else {
                printf("%d", str[j]);
            }  
        }
        printf("\n");
        
    }

    return 0;
}