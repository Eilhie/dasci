#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_str(char **x, char **y){
    char *temp = *x;
    *x = *y;
    *y = temp;
}

void swap(long int *x, long int *y){
    long int temp = *x;
    *x = *y;
    *y = temp;
}



int main(){

    FILE *fp;
    fp = fopen("testdata.in", "r");

    int testcases;
    fscanf(fp, "%d\n", &testcases);

    long int nums[1000];
    char name[1000][100];
    char temp[100];
    for(int i = 0; i < testcases; i++){
        fscanf(fp,"%ld#%[^\n]\n", &nums[i], temp);    
        //name[i] = malloc(strlen(temp)*sizeof(char));
        strcpy(name[i], temp);
    }
    int len = testcases;
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (strcmp(name[j], name[j + 1]) > 0){
                //swap_str(name + j, name + j + 1);
                strcpy(temp, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], temp);
                swap(&nums[j], &nums[j + 1]);
            }
        }
    }


    for(int i = 0; i < testcases; i++){
        printf("%ld %s\n", nums[i], name[i]);
    }

    return 0;
}