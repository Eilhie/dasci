#include <stdio.h>
#include <math.h>

void swap(long int *x, long int *y);
long int partition(long int array[], long int low, long int high);
void quicksort_recursion(long int array[], long int low, long int high);
void quicksort(long int array[], long int length);

int main(){
    long int N;
    scanf(" %ld", &N);
    long int number[N];
    for(int i = 0; i < N; i++){
        scanf(" %ld", &number[i]);
    }

    quicksort(number, N);
    int count = 0;

    for(int i = (N / 2) + 1; i < N; i++){
        if(count == 0){
            printf("%d", number[i]);
            count = 1;
        } else
            printf(" %d", number[i]);
    }
    puts("");
}

void swap(long int *x, long int *y){
    long int temp = *x;
    *x = *y;
    *y = temp;
}


void quicksort(long int array[], long int length){

    quicksort_recursion(array, 0, length-1);
}

void quicksort_recursion(long int array[], long int low, long int high){
    if (low<high){
        long int pivotIndex = partition(array, low, high);
        quicksort_recursion(array, low, pivotIndex-1);
        quicksort_recursion(array, pivotIndex + 1, high);
    }
}

long int partition(long int array[], long int low, long int high){
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