#include <stdio.h>

int main(){
    int umur = 10;
    int *ptr = &umur;

    printf("%d\n", *ptr);
    printf("%d\n", ptr);
    printf("%d\n", umur);
    printf("%d\n", &umur);

    int arr[5] = { 1, 2, 3, 4, 5 };
    int *ptr2 = arr;
 
    printf("%d\n", *ptr2);
    printf("%d\n", *ptr2+1);
    printf("%d\n", *ptr2+2);
}