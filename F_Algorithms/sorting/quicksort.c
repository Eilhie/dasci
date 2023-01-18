#include <stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t; 
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[high], &arr[i + 1]);
    return i + 1;
}

void quickSort(int arr[], int low, int high){
    if(low <= high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){

    int arr[] = {10, 40, 15, 50, 20, 25, 30};
    int len = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, len - 1);

    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    puts("");

    return 0;
}