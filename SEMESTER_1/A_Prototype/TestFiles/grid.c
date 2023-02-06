#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

int partition(char string[], int low, int high){
    int i=low;
    for(int j=low; j<high; j++){
        if(string[j]<=string[high]){
            swap(&string[j], &string[i]);
            i++;
        }
    }
    swap(&string[i], &string[high]);
    return i;
}

void quicksort_recursion(char string[], int low, int high){
    if(low<high){
        int pivotIndex = partition(string, low, high);
        quicksort_recursion(string, low, pivotIndex-1);
        quicksort_recursion(string, pivotIndex+1, high);
    }
}

void quicksort(char string[], int size){
    
    quicksort_recursion(string, 0, size-1);
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
    int T, N;
    scanf("%d %d", &T, &N);
    char *list[250];
    char string[250];
    for(int i = 0; i < T; i++){
        scanf(" %s", string);
        int A = strlen(string);
        quicksort(string, A);
        list[i] = malloc(250*sizeof (char));
        strcpy(list[i], string);
    }
    quicksort_str(list, T);
    for(int i=T-1; i>=0; i--){
        printf("%s\n", list[i]);
    }
}