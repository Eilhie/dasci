#include <stdio.h>

int main(){

    double money;
    int months;
    
    scanf("%lf %d", &money, &months);
    double minterest = 0.07 / 12;
    for(int i = 1; i <= months; i++){
        money += money * minterest;  
    }
    
   printf("%.0f\n", money);

    return 0;
}