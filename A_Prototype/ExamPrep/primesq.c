#include <stdio.h>

int isprime(int num){
    if(num == 0) return 0;
    else if(num == 1) return 1;
    else{
        for(int i = 2; i < num; i++){
            if(num % i == 0) return 0;
        }
    }
    return 1;
}

int main(){

    int start, end;
    scanf("%d %d", &start, &end);
    for(int i = start; i <= end; i++){
        if(isprime(i)) printf("%d", i);
        else printf("-");
    }
    printf("\n");

    return 0;
}