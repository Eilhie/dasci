#include <stdio.h>

unsigned long long int sumseries(int a, int b, unsigned long long int total){
    if(a >= b) return total + b;
    total += a;
    sumseries(a + 1, b, total);
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", sumseries(a,b, 0));
    return 0;
}