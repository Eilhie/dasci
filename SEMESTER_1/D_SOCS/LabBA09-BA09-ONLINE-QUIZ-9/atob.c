#include <stdio.h>

int atob(int a, int b){
    if(a == 1) return a;
    if(a == b) return a;
    else if(a % 2 != 0) return atob(a * 3 + 1, b);
    else if(a % 2 == 0) return atob(a / 2, b);
}

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(atob(a, b) == b) printf("Case #%d: YES\n", i + 1);
        else printf("Case #%d: NO\n", i + 1);
    }

    return 0;
}