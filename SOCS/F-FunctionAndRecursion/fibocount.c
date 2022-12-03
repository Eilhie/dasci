#include <stdio.h>

int fib(int n,int *count){
    *count = *count + 1;
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return (fib(n - 1, count) + fib(n - 2, count));
}

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int num;
        int count = 0;
        scanf("%d", &num);
        fib(num, &count);
        printf("Case #%d: %d\n", i + 1, count);
    }

    return 0;
}