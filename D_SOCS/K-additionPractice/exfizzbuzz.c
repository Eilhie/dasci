#include <stdio.h>
#include <stdlib.h>

void fizzbuzz(int x){
    
    if(x % 3 == 0 && x % 5 == 0) {printf("FizzBuzz\n"); return;}
    if(x % 3 == 0) {printf("Fizz\n"); return;}
    if(x % 5 == 0) {printf("Buzz\n"); return;}
    
    printf("%d\n", x);
}

int main(){
    int x;
    scanf("%d", &x);
    fizzbuzz(x);
    return 0;
}