#include <stdio.h>

int main(){
    int q;
    double list[30][30], a;
    scanf("%d", &q);
    for(int i = 0; i<3; i++){
        scanf("%lf %lf", &list[i][0], &list[i][1]);
    }
    for(int i = 0; i<3; i++){
        a = list[i][1]*list[i][0]/360;
        printf("%.2f\n", a);
    }
}