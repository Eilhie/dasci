#include <stdio.h>

int main(){

    int tc;
    scanf("%d", &tc);
    for(int i = 1; i <= tc; i++){
        int len;
        scanf("%d", &len);
        long long int sum = 0;
        int a;
        for(int i = 0; i < len; i++){
            scanf("%d", &a);
            sum += a;
        }
        printf("Case #%d: %lld\n", i, sum);
    }

    return 0;
}