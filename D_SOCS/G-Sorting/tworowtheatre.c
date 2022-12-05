#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);
long int partition(int array[], long int low, long int high);
void quicksort_recursion(int array[], long int low, long int high);
void quicksort(int array[], long int length);

int main(){

    int size = 6;
    int arr[] = {1, 6, 9, 7, 2, 3};
    quicksort(arr, size);
    int min = 0;
    int max = 0;
    
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    for (int i = 0; i < size-1; i++){
        if (arr[i]-arr[i+1] < min) min = abs(arr[i]-arr[i+1]);
         if (arr[i]+arr[i+1] > max) max = abs(arr[i]-arr[i+1]);
    }
    printf("\n%d\n", min);
    return 0;
}

void swap(int *x, int *y){
    long int temp = *x;
    *x = *y;
    *y = temp;
}


void quicksort(int array[], long int length){

    quicksort_recursion(array, 0, length-1);
}

void quicksort_recursion(int array[], long int low, long int high){
    if (low<high){
        long int pivotIndex = partition(array, low, high);
        quicksort_recursion(array, low, pivotIndex-1);
        quicksort_recursion(array, pivotIndex + 1, high);
    }
}

long int partition(int array[], long int low, long int high){
    long int pivotValue = array[high];

    long int i = low;

    for(int j=low; j<high; j++){
        if(array[j]<=pivotValue){
            swap(&array[i], &array[j]);
            i++;
        }
    }

    swap(&array[i], &array[high]);
    
    return i;
}