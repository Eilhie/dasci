#include <stdio.h>

int main(){

    int arr[] = {1,2,34,5, 6};

    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    puts("");
    int temp;
 
    int i, j;
    for (i = 0; i < 5; i++){
 
        // Last i elements are already in place
        for (j = 0; j < 5; j++){
            if (arr[j] < arr[j + 1])
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
        }
    }
    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    

    return 0;
}