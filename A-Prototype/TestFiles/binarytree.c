#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);

    for(int i = 0; i < testCases; i++){
        int len;
        scanf("%d", &len);
        long int arr[len];
        for(int j = 0; j < len; j++){
            scanf("%d", &arr[j]);
        }
    }

    return 0;
}