#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_str(char **x, char **y){
    char *temp = *x;
    *x = *y;
    *y = temp;
}

int main(){

    FILE *fp;
    fp = fopen("testdata.in", "r");

    int testcases;
    fscanf(fp, "%d\n", &testcases);

    char *nums[1000];
    char *name[1000];
    char temp[100];
    char temp2[100];
    for(int i = 0; i < testcases; i++){
        fscanf(fp,"%s %[^\n]\n", temp2, temp);    
        name[i] = malloc(strlen(temp)*sizeof(char));
        nums[i] = malloc(strlen(temp2)*sizeof(char));
        strcpy(name[i], temp);
        strcpy(nums[i], temp2);
    }
    int len = testcases;
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (strcmp(nums[j], nums[j + 1]) > 0){
                swap_str(name + j, name + j + 1);
                swap_str(nums + j, nums + j + 1);
            }
        }
    }


    for(int i = 0; i < testcases; i++){
        printf("%s %s\n", nums[i], name[i]);
    }

    return 0;
}