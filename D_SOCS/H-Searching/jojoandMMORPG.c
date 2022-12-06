#include <stdio.h>

void swap(unsigned long long int *x, unsigned long long int *y);
int partition(unsigned long long int array[], int low, int high);
void quicksort_recursion(unsigned long long int array[], int low, int high);
void quicksort(unsigned long long int array[], int length);

int main(){

    int len;
    scanf("%d", &len);
    unsigned long long int list[len], power;
    for(int i = 0; i < len; i++){
        scanf("%llu", &list[i]);
    }
    scanf("%llu", &power);
    quicksort(list, len);
    int win = 0;
    for(int i = 0; i < len; i++){
        if(power >= list[i]){
            win++;
            power -= list[i];
        } 
    }
    printf("%d\n", win);
    
    return 0;
}

void swap(unsigned long long int *x, unsigned long long int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(unsigned long long int array[], int length){

    quicksort_recursion(array, 0, length-1);
}

void quicksort_recursion(unsigned long long int array[], int low, int high){
    if (low<high){
        int pivotIndex = partition(array, low, high);
        quicksort_recursion(array, low, pivotIndex-1);
        quicksort_recursion(array, pivotIndex + 1, high);
    }
}

int partition(unsigned long long int array[], int low, int high){
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