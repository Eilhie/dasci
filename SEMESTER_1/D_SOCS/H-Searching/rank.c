#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swapnum(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp; 
}

void swapstr(char **x, char **y){
    char *temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int testcases;
    scanf("%d", &testcases); getchar();
    for(int i = 0; i < testcases; i++){
        int len;
        scanf("%d", &len); getchar();
        char *name[1000];
        int score[1000];
        char temp[100];
        for(int j = 0; j < len; j++){
            scanf("%[^#]#%d", temp, &score[j]); getchar();
            name[j] = malloc(strlen(temp)*sizeof(char));
            strcpy(name[j], temp);
            //printf("%s %d\n", name[j], score[j]);
        }
        char search[50];
        scanf("%s", search);

        for(int j = 0; j < len - 1; j++){
            for(int k = 0; k < len - j - 1; k++){
                if(score[k] < score[k + 1]){
                    swapnum(&score[k], &score[k + 1]);
                    swapstr(name + k, name + k + 1);
                } else if (score[k] == score[k + 1]){
                    if(strcmp(name[k], name[k + 1]) > 0){
                        swapstr(name + k, name + k + 1);
                    }
                }
            }
        }
        printf("Case #%d: ", i + 1);
        for(int j = len - 1; j >= 0; j--){
            if(strcmp(name[j], search) == 0){
                printf("%d\n", j + 1);
            }
        }

    }
    
    return 0;
}