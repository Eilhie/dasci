#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_str(char **x, char **y){
    char *temp = *x;
    *x = *y;
    *y = temp;
}

void swap_chr(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

void swap(double *x, double *y){
    double temp = *x;
    *x = *y;
    *y = temp;
}

int main(){

    FILE *fp;
    fp = fopen("testdata.in", "r");

    char *town[100], type[100];
    double temperature[100];
    char ntemp[1010];
    int i = 0;
    double sort[100];

    while (!feof(fp)) {
        fscanf(fp, "%[^#]#%lf#%c\n", ntemp, &temperature[i], &type[i]);
        town[i] = malloc(1010*sizeof(char));
        strcpy(town[i], ntemp);
        if(type[i] == 'F'){
            sort[i] = (temperature[i] - 32) * 5 / 9;
        } else sort[i] = temperature[i];
        i++;
    }

    for (int j = 0; j < i; j++){
        for (int k = 0; k < i - j - 1; k++){
            if (sort[k] > sort[k + 1]){
                swap_str(town + k, town + k + 1);
                swap_chr(&type[k], &type[k + 1]);
                swap(&temperature[k], &temperature[k + 1]);
                swap(&sort[k], &sort[k + 1]);
            } else if(sort[k] == sort[k + 1]){
                swap_str(town + k, town + k + 1);
                swap_chr(&type[k], &type[k + 1]);
            }
        }
    }
    // puts("");
    // for(int j = 0; j < i; j++){
    //     printf("%f\n", sort[j]);
    // }
    // puts("");
    for(int d = 0; d < i; d++){
        printf("%s is %.2f%c\n", town[d], temperature[d], type[d]);
    }
    // puts("");
    fclose(fp);

    return 0;
}