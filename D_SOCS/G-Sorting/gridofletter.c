#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

char partition(char array[], int low, int high){
    int pivotValue = array[high];

    int i = low;

    for(int j=low; j<high; j++){
        if(array[j]<=pivotValue){
            swap(&array[i], &array[j]);
            i++;
        }
    }

    swap(&array[i], &array[high]);
    
    return i;
}

void quicksort_recursion(char array[], int low, int high){
    if (low<high){
        int pivotIndex = partition(array, low, high);
        quicksort_recursion(array, low, pivotIndex-1);
        quicksort_recursion(array, pivotIndex + 1, high);
    }
}

void quicksort(char array[], int length){

    quicksort_recursion(array, 0, length-1);
}

void swap_str(char **x, char **y){
    char *temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort_str(char *list[], int size){
    unsigned int i, pvt=0;
    if (size <= 1)
        return;
    swap_str(list+((unsigned int)rand() % size), list+size-1);
    for (i=0;i<size-1;++i){
        if (strcmp(list[i], list[size-1]) < 0)
            swap_str(list+i, list+pvt++);
    }
    swap_str(list+pvt, list+size-1);
    quicksort_str(list, pvt++);
    quicksort_str(list+pvt, size - pvt);
}

int main(){

    int R, C;
    scanf("%d %d", &R, &C);
    char *matrix[250];

    char temp[250];
    for(int i = 0; i < R; i++){
        scanf(" %s", temp);    
        int len = strlen(temp);

        quicksort(temp, len);
        matrix[i] = malloc(250*sizeof(char));
        strcpy(matrix[i],temp);
    } 
    
    quicksort_str(matrix, R);

    for(int i = R - 1; i >= 0 ; i--){
        printf("%s\n", matrix[i]);
    }

    return 0;
}