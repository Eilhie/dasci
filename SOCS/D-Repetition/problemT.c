#include <stdio.h>

int main(){

    int testCases, i;
    int result = 0;

    scanf("%d", &testCases);

    int tc[testCases], tv[testCases], ts[testCases];

    for(i = 0; i < testCases; i++){
        scanf("%d %d %d", &tc[i], &tv[i], &ts[i]);
    }

    for(i = 0; i < testCases; i++){
        if(tv[i] > ts[i]){
            result += 1;
        }
    }

    printf("%d\n", result);

    return 0;
}