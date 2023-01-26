#include <stdio.h>

int recursion(int m, int n, int *result){
    if(m <= n){
        *result += m % 10;
        return recursion(m+m, n, result);
    } 
}

int main(){

    int testCases;
    scanf("%d", &testCases); getchar();
    for(int i = 0; i < testCases; i++){
        long long int n, m;
        scanf("%lld %lld", &n, &m); getchar();

        long long int result = 0;
        // for (long long int j = m; j <= n; j += m) {
        //     result += j % 10;
        // }
        int res = recursion(m,n,&result);

        printf("Case #%d: %lld\n", i + 1, result);

    }

    return 0;
}

