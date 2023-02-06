#include <stdio.h>

int main(){

    long long int testCases;
    scanf("%lld", &testCases);

    long long int totalItem[testCases];
    long long int numsOfItem[testCases][100];

    for(int i = 0; i < testCases; i++){
        scanf("%lld", &totalItem[i]);
        for(int j = 0; j < totalItem[i]; j++){
            scanf("%lld", &numsOfItem[i][j]);
        }
    }
    
    long long int result[testCases];

    for(int i = 0; i < testCases; i++){
        result[i] = 0;
        for(int j = 0; j < totalItem[i]; j++){
            result[i] += numsOfItem[i][j];
            // printf("%d ", numsOfItem[i][j]);
        }
        printf("Case #%d: %lld\n", i + 1, result[i]);
    }

    return 0;
}