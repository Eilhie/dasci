#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swapstr(char **x, char **y){
    char *temp = *x;
    *x = *y;
    *y = temp;
}

void swapchar(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int size;
    scanf("%d", &size);
    char *photo[size];
    char temp[150];
    for(int i = 0; i < size; i++){
        scanf("%s", temp);
        photo[i] = malloc(strlen(temp)*sizeof(char));
        strcpy(photo[i], temp);
    }
    
    for(int i = 0, j = size - 1; i < j; i++, j--){
        swapstr(photo + i, photo + j);
    }

    for(int k = 0; k < size; k++){
        for(int i = 0, j = size - 1; i < j; i++, j--){
            swapchar(&photo[k][i], &photo[k][j]);
        }
    }
    
    for(int i = 0; i < size; i++){
        printf("%s\n", photo[i]);
    }

    return 0;
}
