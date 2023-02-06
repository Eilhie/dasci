#include <stdio.h>

int main(){

    long int x;
    long int start = 0;
    scanf("%ld", &x);
    long int list[x];

    for(long int i = 0; i < x; i++){
        scanf("%ld", &list[i]);
    }

    for(long int i = 0; i < x; i++){
        start = start + list[i];
        if(start == 9){
            start = 21;
        }else if(start == 33){
            start = 42;
        }else if(start == 76){
            start = 92;
        }
        if(start == 53){
            start = 37;
        }else if(start == 80){
            start = 59;
        }else if(start ==97){
            start = 88;
        }
    }

    printf("%d\n", start);

    return 0;
}