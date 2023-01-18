#include <stdio.h>

// int sum(long long d, long long n){
//     int tot = 0;
//     for (int i = 0; i < d; i++){
//         printf ("n equals to %d\n", n);
//         tot = 0;
//         for (int j = 1; j<=n; j++){
//             // printf ("counting %d in %d call\n", j, i);
//             tot += j;
//         }
//         n = tot;
//     }
//     return n;
// }

int sum_recursive(long long d, long long n, int depth) {
    if (depth == d) {
        return n;
    }
    int tot = 0;
    for (int j = 1; j <= n; j++) {
        tot += j;
    }
    return sum_recursive(d, tot, depth + 1);
}


int main(){
    long long int d, n;
    //long long int tot = 0;
    scanf ("%lld %lld", &d, &n); getchar();
    
    printf ("%lld\n", sum_recursive(d, n, 0));
}