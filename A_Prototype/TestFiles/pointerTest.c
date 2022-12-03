#include <stdio.h>

int main(){

    int arr[5] = { 1, 2, 3, 4, 5 };
    int *ptr = arr;
    
    printf("%d\n", *ptr); // equivalen dengan arr[0]
    printf("%d\n", *ptr+1); // equivalen dengan arr[1]
    printf("%d\n", *ptr+2); // equivalen dengan arr[2]
    printf("%d\n", *ptr+3); // equivalen dengan arr[3]

    return 0;
}