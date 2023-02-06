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
    
    long int selisih[N-1];

    for(int i = 0 ; i < N - 1; i++){
        selisih[i] = abs(number[i] - number[i + 1]);
    }

    long int max = selisih[0];
    long int max_index[N];
    for(int i = 1; i < N - 1; i++){
        if(selisih[i] > max){
            max = selisih[i];
        }
    }
    int count = 0;
    for(int i = 0; i < N - 1; i++){
        if(max == abs(number[i] - number[i + 1])){
            if(count == 0){
                printf("%ld %ld",number[i], number[i + 1]);
                count = 1;
            } else {
               printf(" %ld %ld",number[i], number[i + 1]);
            } 
        }
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