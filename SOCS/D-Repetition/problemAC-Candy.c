#include<stdio.h>

int main (){
    long long int n, cnum, money, price[10020];
    scanf("%lld", &n);
    for(int i = 1; i<=n; i++){
        scanf("%lld %lld", &cnum, &money);
        long long int candy=0;
        long long int minPrice = 10e6;

        for(int i=0; i < cnum; i++){
            scanf("%lld", &price[i]);

            if(price[i] < minPrice){
                minPrice = price[i];
            }
        }
        candy = money / minPrice;
        printf("Case #%d: %lld\n", i, candy);
    }

    return 0;
}