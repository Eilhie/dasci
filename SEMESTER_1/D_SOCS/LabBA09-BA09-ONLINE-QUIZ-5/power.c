#include <stdio.h>
#include <math.h>

int fastpow(long long int a, long long int b){

    long long int ans = 1;
    
    int n = 1000000007;
    while(b > 0){
        if((b&1) != 0){
            ans = (ans * (a % n) % n);
        }
        a = (a % n) * (a % n);
        b = b >> 1;
    }
    return ans;
}


int main(){

    int testCases;

    long long int base, power;

    scanf("%d", &testCases);

    for(int i = 0; i < testCases; i++){
        scanf("%lld %lld", &base, &power);
        
        printf("Case #%d: %lld\n", i + 1, fastpow(base,power));
    }

    return 0;
}