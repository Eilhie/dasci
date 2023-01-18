#include <stdio.h>

int recursion(int a, int *count){
    if(a == 3 || a == 4) *count = *count + 1;
    if(a == 0) return 1;
    else if(a == 1) return 2;
    
    if(a % 3 == 0) return recursion(a - a / 3, count) + 1;

    return recursion(a - 1, count) + a + recursion(a - 2, count) + 1;
}

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int a; 
        int count = 0;
        scanf("%d", &a);

        printf("Case #%d: %d ", i + 1, recursion(a, &count));
        printf("%d\n", count);
    }

    return 0;
}