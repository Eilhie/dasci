#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);

    double a,b,c,d,e,f;
    scanf("%lf %lf %lf %lf %lf %lf", &a,&b,&c,&d,&e,&f);


    printf("%.2f\n%.2f\n%.2f\n", b*a/100, d*c/100, f*e/100);

    
    return 0;
}