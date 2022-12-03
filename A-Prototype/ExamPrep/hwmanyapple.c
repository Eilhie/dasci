#include <stdio.h>

int main(){

    int a, b;
    scanf("%d %d", &a, &b);
    for(int i = a; i <= b; i++){
        if(i % 7 == 6 && i % 5 == 4 && i % 3 == 2){
            printf("%d\n", i);
        }
    }

    return 0;
}