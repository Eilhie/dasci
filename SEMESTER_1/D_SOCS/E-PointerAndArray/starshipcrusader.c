#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases); 
    for(int i = 0; i < testCases; i++){
        int lenght;
        scanf("%d", &lenght);
        long int arr1[lenght], arr2[lenght];
        for(int j = 0; j < lenght; j++){
            scanf("%d", &arr1[j]);
        }
        for(int j = 0; j < lenght; j++){
            scanf("%d", &arr2[j]);
        }
        int sum = 0;

        for(int j = 0; j < lenght; j++){
            if(!(arr1[j] >= arr2[j])){
                sum += 1;
            }
        }
        printf("Case #%d: %d\n", i + 1, sum);
    }


    return 0;
}
