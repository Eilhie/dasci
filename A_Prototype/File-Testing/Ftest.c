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

    char *name[100], *title[100];
    long int view[100];
    char ntemp[1010], ttemp[1010];
    int i = 0;
    while (!feof(fp)) {
        fscanf(fp, "%[^#]#%[^#]#%ld\n", ttemp, ntemp, &view[i]);
        name[i] = malloc(1010*sizeof(char));
        strcpy(name[i], ntemp);
        title[i] = malloc(1010*sizeof(char));
        strcpy(title[i], ttemp);
        // printf("%s %s %ld", title[i], name[i], view[i]);
        i++;
    }
    for (int j = 0; j < i; j++){
        for (int k = 0; k < i - j - 1; k++){
            if (view[k] < view[k + 1]){
                swap_str(name + k, name + k + 1);
                swap_str(title + k, title + k + 1);
                swap(&view[k], &view[k + 1]);
            } else if(view[k] == view[k + 1]){
                swap_str(name + k, name + k + 1);
                swap_str(title + k, title + k + 1);
            }
        }
    }

    for(int d = 0; d < i; d++){
        printf("%s by %s - %ld\n", title[d], name[d], view[d]);
    }
    // puts("");
    fclose(fp);

    return 0;
}