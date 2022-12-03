#include <stdio.h>
#include <math.h>

int main(){
    double get;
    double total = 0;
    for(int i = 0; i < 12; i++){
        scanf("%lf, ", &get);
        total += get;
    }
    double touris = floor(total * 7 / 100);
    double cleaning = floor(total * 5 / 100);
    printf("%.2f, %.2f, %.2f\n", touris, cleaning, (total - touris - cleaning));
    return 0;
}
