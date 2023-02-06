#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        unsigned long long int num, reversed_num = 0, remainder, saved;
        scanf("%llu", &num);
        saved = num;
        while (num != 0)
        {
            remainder = num % 10;
            reversed_num = reversed_num * 10 + remainder;
            num /= 10;
        }

        printf("Case #%d: %llu\n", i + 1, (saved + reversed_num));

    }

    return 0;
}