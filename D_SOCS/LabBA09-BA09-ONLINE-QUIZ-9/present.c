#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int len;
        scanf("%d", &len);
        int arr[len];
        int max = 0;
        int count = 0;
        for(int j = 0; j < len; j++){
            scanf("%d", &arr[j]);
            if(max < arr[j]) max = arr[j];
        }

        for(int j = 0; j < len; j++) {
            if(arr[j] == max) count++;
        }

        printf("Case #%d: %d\n", i + 1, count);
    }

    return 0;
}