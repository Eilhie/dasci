#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap_str(char **x, char **y){
    char *temp = *x;
    *x = *y;
    *y = temp;
}

int binary_search(char *list_of_words[], int size, char *target){
    int bottom= 0;
    int mid;
    int top = size - 1;

    while(bottom <= top){
        mid = (bottom + top)/2;
        if (strcmp(list_of_words[mid], target) == 0){
            // printf("%s found at location %d.\n", target, mid+1);
            return mid;
        } else if (strcmp(list_of_words[mid], target) > 0){
            top = mid - 1;
        } else if (strcmp(list_of_words[mid], target) < 0){
            bottom = mid + 1;
        }
    }
    return -1;
}

int main(){

    FILE *fp;
    fp = fopen("testdata.in", "r");

    int datacount;
    fscanf(fp, "%d\n", &datacount);
    char *key[100];
    char *actual[100];
    for(int i = 0; i < datacount; i++){
        char KeyTemp[100], ActualTemp[100];
        fscanf(fp, "%[^#]#%s\n", KeyTemp, ActualTemp);
        key[i] = malloc(strlen(KeyTemp)*sizeof(char));
        actual[i] = malloc(strlen(ActualTemp)*sizeof(char));
        strcpy(key[i], KeyTemp);
        strcpy(actual[i], ActualTemp);
    }

    for (int i = 0; i < datacount - 1; i++){
        for (int j = 0; j < datacount - i - 1; j++){
            if (strcmp(key[j], key[j + 1]) > 0){
                swap_str(key + j, key + j + 1);
                swap_str(actual + j, actual + j + 1);
            }
        }
    }

    int testcases;
    fscanf(fp, "%d\n", &testcases);
    for(int i = 0; i < testcases; i++){
        char string[200];
        fscanf(fp, "%[^\n]\n", string);
        char list[200][200];
        char *token = strtok(string, " ");
        int l = 0;
        while(token!=NULL){
            strcpy(list[l], token);
            token = strtok(NULL, " ");
            l++;
        }
        printf("Case #%d:\n", i + 1);
        for(int j = 0; j < l; j++){
            int result = binary_search(key, datacount, list[j]);
            
            if(result >= 0){
                strcpy(list[j], actual[result]);
            } 

            if(j == l - 1) printf("%s\n", list[j]);
            else printf("%s ", list[j]);
        }
    }

    fclose(fp);

    return 0;
}