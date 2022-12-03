#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_str(char **x, char **y){
    char *temp = *x;
    *x = *y;
    *y = temp;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}



int main(){

    FILE *fp;
    fp = fopen("filedata.in", "r");

    int testcases;
    fscanf(fp, "%d\n", &testcases);

    int nums[testcases];
    char *name[testcases];
    char temp[100];
    for(int i = 0; i < testcases; i++){
        fscanf(fp,"%d#%[^\n]\n", &nums[i], temp);    
        int len = strlen(temp);
        name[i] = malloc(100*sizeof(char));
        strcpy(name[i], temp);
    }
    int len = testcases;
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (strcmp(name[j], name[j + 1]) > 0){
                swap_str(name + j, name + j + 1);
                swap(&nums[j], &nums[j + 1]);
            }
        }
    }


    for(int i = 0; i < testcases; i++){
        printf("%d %s\n", nums[i], name[i]);
    }

    return 0;
}