#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapNum(int *x, int *y){
    int temp;
    *x = *y;
    *y = temp;
}

void swapStr(char **a, char **b){
    char *temp;
    strcpy(temp, *a);
    strcpy(*a, *b);
    strcpy(*b, temp);
}

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int len;
        scanf("%d", &len);
        char *name[len];
        
        int score[len];
        for(int j = 0; j < len; j++){
            char temp[100];
            scanf("%[^#]#%d", temp, &score[j]); getchar();
            name[j] = malloc(100*sizeof(char));
            strcpy(name[j], temp);
        }
        char search[100];
        scanf("%[^\n]", search);


        

        for(int j = 0; j < len - 1; j++){
            for(int k = 0; k < len - 1 - j; k++){
                if(score[k] > score[k + 1]){
                    swapNum(&score[k], &score[k + 1]);
                    swapStr(name + k, name + k + 1);
                } else if(score[k] == score[k + 1]){
                    if(strcmp(name[k], name[k + 1]) > 0){
                        swapStr(name + k, name + k + 1);
                    }
                }
            }
        }

        // for(int j = 0; j < len; j++){
        //     printf("%s %d\n", name[j], score[j]);
        // }
        
        printf("Case #%d: \n", i + 1);
        for(int j = 0; j < len; j++){
            printf("%d\n", strcmp(search, name[j]));
            printf("%s %s\n", search, name[j]);
        }
    }
    return 0;
}