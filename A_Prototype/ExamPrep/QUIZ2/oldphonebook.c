#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **x, char **y){
    char *temp = *x;
    *x = *y;
    *y = temp;
}

int partition(char *arr[], int low, int high){
    char *pivot = arr[high];
    int i = low - 1;
      for (int j = low; j <= high - 1; j++){

        if (strcmp(arr[j], pivot) < 0){
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(char *arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(){

    
    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int n, m;
        scanf("%d %d", &n, &m);
        char **query = malloc(n*sizeof(char*)); 
        char **list = malloc(m*sizeof(char*)); 
        char *temp;
        for(int i = 0; i < n; i++){
            query[i] = malloc(15*sizeof(char)); 
            scanf("%s", temp); getchar();
            strcpy(query[i], temp);
        }
        quicksort(query, 0, n - 1);
        for(int i = 0; i < m; i++){
            list[i] = malloc(15*sizeof(char)); 
            scanf("%s", temp);
            strcpy(list[i], temp);
        }
        for(int i = 0; i < n; i++){
            printf("%s ", query + i);
        }
        printf("Case #%d: \n", i + 1);

    }

    return 0;
}