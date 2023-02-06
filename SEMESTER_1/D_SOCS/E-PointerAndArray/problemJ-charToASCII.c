#include <stdio.h>
#include <string.h>

int main(){

    int testCases;

    scanf("%d", &testCases); getchar();

    for(int i = 0; i < testCases; i++){
        char string[1000];
        scanf("%[^\n]", string);
        printf("Case %d: ", i + 1);
        for(int j = 0; j < strlen(string); j++){
            if(j == strlen(string) - 1){
                printf("%d\n", string[j]);
            } else{
                printf("%d-", string[j]);
            }
        }
        getchar();
    }

    return 0;
}