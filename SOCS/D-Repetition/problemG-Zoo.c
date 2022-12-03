#include <stdio.h>

int main(){

    long int testCases;
    long long int total = 0;
    scanf("%ld", &testCases);

    long int nums[100000];

    for(int i = 0; i < testCases; i++){
        scanf("%ld", &nums[i]);
    }

    for(int i = 0; i < testCases; i++){
        total = total + nums[i];
    }
    printf("%lld\n", total);

    return 0;
}