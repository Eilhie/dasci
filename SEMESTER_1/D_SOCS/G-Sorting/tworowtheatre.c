#include <stdio.h>
#include <stdlib.h>

void swap( int *x,  int *y);
int partition( int *array,  int low,  int high);
void quicksort_recursion( int *array,  int low,  int high);
void quicksort( int *array,  int length);
int binarySearch( int *array, int l, int r, int search);

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        int N;
        scanf(" %d", &N);
        int *list;
        list = malloc(N*sizeof list);
        for(int j=0; j<N; j++){
            scanf(" %d", &list[j]);
        }
        quicksort(list, N);
        int min1=0, min2=0;
        for(int j=0; j<N/2-1; j++){
            if(abs(list[j]-list[j+1])>min1){
                min1 = abs(list[j]-list[j+1]);
            }
        }
        for(int j=N/2; j<N-1; j++){
            if(abs(list[j]-list[j+1])>min2){
                min2 = abs(list[j]-list[j+1]);
            }
        }
        printf("Case #%d: ", i+1);
        if(min1>=min2){
            printf("%d\n", min1);
        }else{
            printf("%d\n", min2);
        }
    }
}

void swap( int *x,  int *y){
     int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort( int *array,  int length){

    quicksort_recursion(array, 0, length-1);
}

void quicksort_recursion( int *array,  int low,  int high){
    if (low<high){
         int pivotIndex = partition(array, low, high);
        quicksort_recursion(array, low, pivotIndex-1);
        quicksort_recursion(array, pivotIndex + 1, high);
    }
}

 int partition( int *array,  int low,  int high){
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

int binarySearch( int *array, int l, int r, int search){
    if(l<=r){
        int mid = l+(r-l)/2;

        if(array[mid] == search){
            return mid+1;
        }

        if(array[mid] > search){
            return binarySearch(array, l, mid-1, search);
        }
        return binarySearch(array, mid+1, r, search);
    }
    return -1;
}