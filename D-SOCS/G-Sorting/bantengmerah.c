#include <stdio.h>

void swap(int *x, int *y);
int partition(int array[], int low, int high);
void quicksort_recursion(int array[], int low, int high);
void quicksort(int array[], int length);
int binarySearch(int arr[], int x, int low, int high);

int main(){
    int len;    
    int x;
    scanf("%d", &len);
    int list[len];
    for(int i = 0; i < len; i++){
        scanf(" %d", &list[i]);
    }

    quicksort(list, len);
    
    scanf("%d", &x);
    int search;
    for(int i = 0; i < x; i++){
        scanf(" %d", &search);  
        printf("%d\n", binarySearch(list, search, 0, len) + 1);
    }
    return 0;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int array[], int length){

    quicksort_recursion(array, 0, length-1);
}

void quicksort_recursion(int array[], int low, int high){
    if (low<high){
        int pivotIndex = partition(array, low, high);
        quicksort_recursion(array, low, pivotIndex-1);
        quicksort_recursion(array, pivotIndex + 1, high);
    }
}

int partition(int array[], int low, int high){
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

int binarySearch(int arr[], int x, int low, int high){
    if (low > high)
        return -2;

    else{
        int mid = (low + high) / 2;
        if(x == arr[mid])
            return mid;

        else if(x > arr[mid])        // x is on the right side
            return binarySearch(arr, x, mid + 1, high);
        
        else                        // x is on the left side
            return binarySearch(arr, x, low, mid - 1);
    }
}