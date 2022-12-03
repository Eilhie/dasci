#include <stdio.h>
#include <string.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        char string[101];
        int length, life;
        scanf("%d %d", &length, &life);
        getchar();
        gets(string);
        int count = 0;
        for(int j = 0; j < length; j++){
            if(string[j] == '1'){
                count++;
            }
        }

        int left = 0, right = 0;
        for(int j = 0; j < length; j++){
            if(string[j] == '1'){
                left = j;
                break;
            }
        }
        for(int j = length - 1; j >= 0; j--){
            if(string[j] == '1'){
                right =  length - 1 - j;
                break;
            }
        }


        if(count == 0 || count == 1){
            if(length <= life){
                printf("ALIVE\n");
            } else printf("DEAD\n");
        } else {
            if(left < life && right < life){
                printf("ALIVE\n");
            } else {
                printf("DEAD\n");
            }
        }

        // printf("Case #%d: \n", i + 1);

    }
    return 0;
}
