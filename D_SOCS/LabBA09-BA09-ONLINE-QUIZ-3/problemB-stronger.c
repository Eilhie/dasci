#include <stdio.h>

int main(){

    long int hit;

    scanf("%ld", &hit);
    long int result = 0;

    for(int i = 0; i < hit+1; i++){
        long int atk = (100 + 50 * (i-1));
        result += atk ;
    }

    printf("%ld\n", result);

    return 0;
}