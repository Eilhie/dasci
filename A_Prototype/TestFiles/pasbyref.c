#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void arr(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d\n", array[i]);
    }
}

int main(){

    int a = 10, b = 1;
    int size = 5;
    int array[] = {1,2,3,4,5};
    // printf("%d %d\n", a, b);
    // swap(&a, &b);
    // printf("%d %d\n", a, b);

    arr(array, size);
    return 0;
}