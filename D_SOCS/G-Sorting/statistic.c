#include <stdio.h>

void swap(int *x, int *y);
int partition(int array[], int low, int high);
void quicksort_recursion(int array[], int low, int high);
void quicksort(int array[], int length);

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int len;
        scanf("%d", &len);
        int list[len];
        double total = 0;
        for(int j = 0; j < len; j++){
            scanf(" %d", &list[j]);
            total += list[j];
        }   
        quicksort(list, len);

        printf("Case #%d:\n", i + 1);
        printf("Mean : %.2f\n", total / len); 

        if(len % 2 != 0){
            int mid = len / 2;
            printf("Median : %.2f\n", (double)list[mid]);
        } 
        else {
            int mid = len / 2;
            double median = (double)(list[mid] + list[mid - 1]) / 2;
            printf("Median : %.2f\n", median);
        }
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

