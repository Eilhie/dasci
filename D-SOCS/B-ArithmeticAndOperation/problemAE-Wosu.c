#include <stdio.h>

int main(){

    long long int total = 0, turn, atk;

    scanf("%lld", &turn);

    for(int i = 1; i <= turn; i++){
        atk = 100 +  50 * (i-1);
        total += atk;
    }
    printf("%lld\n",total);

    return 0;
}

