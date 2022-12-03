#include <stdio.h>

int main(){
    int x;
    int n = 1;
    scanf("%d",&x);
    for(int i = 0; i < x; i++){
        n = (n*2)+1;
    }

    printf("%d\n", n);
}