#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);

    for(int i = 0; i < testCases; i++){
        int size;
        scanf("%d", &size);
        int arr[size];
        for(int j = 0; j < size; j++){
            scanf("%d", &arr[j]);
        }
        int temp;
        for(int j = 0; j < size/2; j++){
            temp = arr[j];
            arr[j] = arr[size-j-1];
            arr[size-j-1] = temp;
        }
        printf("Case #%d: ", i + 1);
        for(int j = 0; j < size; j++){
            if(j == size-1){
                printf("%d\n", arr[j]);
            } else{
                printf("%d ", arr[j]);
            }
        }
    }

    return 0;
}
