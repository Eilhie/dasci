#include <stdio.h>

int main(){

    int n,m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i <= m; i++){
        printf("%d\n", n);
        n = n + 1;
    }

    return 0;
}