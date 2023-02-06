#include <stdio.h>
#include <string.h>

int main(){

    int testCases;
    scanf("%d", &testCases); 
    getchar();

    for(int i = 0; i < testCases; i++){
        char string[1000];
        scanf("%s", string);
        printf("Case %d: ", i + 1);
        char temp;

        for (int j = 0; j < (strlen(string) / 2); j++){  
            temp = string[j];  
            string[j] = string[strlen(string) - j - 1];  
            string[strlen(string) - j - 1] = temp;  
        }  

        for(int j = 0; j < strlen(string); j++){
            printf("%d", (string[j] % 2));
        }
        printf("\n");
    }

    return 0;
}