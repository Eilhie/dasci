#include <stdio.h>

int notfibo(int f0, int f1, int fk){
    int t1 = f0, t2 = f1;
    int nextTerm = t1 + t2;

    for (int i = 3; i <= fk; ++i) {
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    return nextTerm;
}

int main(){

    int f0,f1, fk;
    scanf("%d %d %d", &f0, &f1, &fk);
    printf("%d\n", notfibo(f0, f1, fk));
    return 0;
}