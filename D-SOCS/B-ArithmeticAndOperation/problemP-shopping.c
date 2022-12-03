#include <stdio.h>

int main(){

    double x,x1,x2,x3,y,y1,y2,y3;
    scanf("%lf %lf",&x,&y);
    scanf("%lf %lf",&x1,&y1);
    scanf("%lf %lf",&x2,&y2);
    scanf("%lf %lf",&x3,&y3);

    printf("$%.2f\n", (100 / (100-x) * y));
    printf("$%.2f\n", (100 / (100-x1) * y1));
    printf("$%.2f\n", (100 / (100-x2) * y2));
    printf("$%.2f\n", (100 / (100-x3) * y3));

    return 0;
}