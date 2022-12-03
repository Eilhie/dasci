#include <stdio.h>

void swap(int *x, int *y);
int partition(int array[], int low, int high);
void quicksort_recursion(int array[], int low, int high);
void quicksort(int array[], int length);

int main(){
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        int N, max1, max2;
        scanf(" %d", &N);
        int number[N];
        for(int i=0; i<N; i++){
            scanf(" %d", &number[i]);
        }
        quicksort(number, N);
        
        printf("Case #%d: %d\n", i+1, number[N-1]+number[N-2]);
    }
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