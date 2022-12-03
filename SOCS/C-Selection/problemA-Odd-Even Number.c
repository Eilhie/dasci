#include <stdio.h>

int main(){

    int x;
    scanf("%d",&x);

    if(x % 2 == 0){
        printf("EVEN\n");
    }else if(x % 2 != 0){
        printf("ODD\n");
    }
    return 0;
}