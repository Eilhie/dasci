#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 1, 2, 3};
    int 
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, count;
    int min = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] < min) min = arr[i];
    }
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > 1 && arr[i] == min) {
            printf("Number %d appears %d times \n", arr[i], count);
        }
    }
    return 0;
}