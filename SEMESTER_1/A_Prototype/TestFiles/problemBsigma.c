#include <stdio.h>

int main(){

    long int testCases;
    long int lenArr;

    scanf("%ld", &lenArr);

    long int index[lenArr];

    for(int i = 0; i < lenArr; i++){
        scanf("%ld", &index[i]);
    }

    scanf("%ld", &testCases);

    long int range[testCases][testCases];

    for(int i = 0; i < testCases; i++){
        scanf("%ld %ld", &range[i][0], &range[i][1]);
        // printf("%ld %ld\n", range[i][0], range[i][1]);
    }    

    long int result[testCases];

    for(int i = 0; i < testCases; i++){
        result[i] = 0;
        // printf("%ld %ld\n", range[i][0],range[i][1]);

        for( int j = range[i][0]; j <= range[i][1]; j++){
            result[i] += index[j - 1];
            // printf("%ld\n", result[i]);
        }

        printf("Case #%d: %ld\n", i + 1, result[i]);
    }

    return 0;
}