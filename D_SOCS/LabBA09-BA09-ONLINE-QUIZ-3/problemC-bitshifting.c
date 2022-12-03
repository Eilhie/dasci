#include <stdio.h>

int main(){

    int testCase;
    scanf("%d", &testCase);

    int a[testCase], b[testCase];

    for(int i = 0; i < testCase; i++){
        scanf("%d %d", &a[i], &b[i]);
    }

    for(int i = 0; i < testCase; i++){
        printf("%d\n", ((a[i]/b[i]) << b[i]));
    }

    return 0;
}