#include <stdio.h>

int oddjobonaci(int a){
    if (a <= 1) return a;
    if (a % 2 != 0) {
        return 1;
    }
    return oddjobonaci(a - 1) + oddjobonaci(a - 2);
}

int main(){

    int a;
    scanf("%d", &a);

    printf("%d\n", oddjobonaci(a));

    return 0;
}
