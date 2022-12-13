#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
      for (int j = low; j <= high - 1; j++){

        if (arr[j] < pivot){
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(){

    int arr[] = {10, 40, 15, 50, 20, 25, 30};
    int len = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, len - 1);

    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    puts("");

    return 0;
}