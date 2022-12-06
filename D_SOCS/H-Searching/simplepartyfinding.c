#include <stdio.h>

void swap( int *x,  int *y);
int partition( int *array,  int low,  int high);
void quicksort_recursion( int *array,  int low,  int high);
void quicksort( int *array,  int length);

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

int main(){
    int testcases;
    scanf("%d", &testcases);
    for(int i = 0; i < testcases; i++){
        int len;
        scanf("%d", &len); getchar();
        int mmr[len];
        int search;
        for(int j = 0; j < len; j++){
            scanf("%d", &mmr[j]);
        }
        scanf("%d", &search); getchar();
        quicksort(mmr, len);
        int res = binarySearch(mmr, 0, len, search);
        printf("CASE #%d: ", i + 1);
        if(res == -1){
            printf("-1 -1\n");
        } else if(res == len){
            printf("%d %d\n", mmr[res - 2], mmr[res - 1]);
        } else {
            printf("%d %d\n", mmr[res - 1], mmr[res]);
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