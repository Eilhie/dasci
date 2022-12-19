#include <stdio.h>
#include <math.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        double area = (2 * 3.14 * x * y) + 2 * 3.14 * pow(x,2);
        printf("Case #%d: %.2f\n", i + 1, area);

    }

    return 0;
}