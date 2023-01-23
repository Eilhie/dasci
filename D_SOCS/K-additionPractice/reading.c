// #include <stdio.h>


// int main(){

//     int testCases;
//     scanf("%d", &testCases); getchar();
//     for(int i = 0; i < testCases; i++){
//         long long int tpages, modulo;
//         scanf("%lld %lld", &tpages, &modulo); getchar();

//         long long int result = 0;
//         for (long long int i = (0 + modulo - 1) / modulo * modulo; i <= tpages / modulo; i++) {
//             result += (i * modulo) % 10;
//         }

//         printf("Case #%d: %lld\n", i + 1, result);

//     }

//     return 0;
// }

#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases); getchar();
    for(int i = 0; i < testCases; i++){
        long long int n, m;
        scanf("%lld %lld", &n, &m); getchar();

        long long int result = 0;
        for (long long int j = m; j <= n; j += m) {
            result += j % 10;
        }

        printf("Case #%d: %lld\n", i + 1, result);

    }

    return 0;
}

