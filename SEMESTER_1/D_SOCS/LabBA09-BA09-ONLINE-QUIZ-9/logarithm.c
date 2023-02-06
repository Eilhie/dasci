// #include <stdio.h>
// #include <math.h>

// unsigned long long int solve(unsigned long long int A, unsigned long long int N) {
//   unsigned long long int B = 0;
//   while (pow(A, B) < N) {
//     B = B + 1;
//   }
//   return B - 1;
// }

// int main() {
//     int testCases;
//     scanf("%d", &testCases);
//     for(int i = 0; i < testCases; i++){
//         unsigned long long int x, y;
//         scanf("%llu %llu", &x, &y);

//         printf("Case #%d: %llu\n", i + 1, solve(x, y));

//     }

// }

#include <stdio.h>
unsigned long long int power(unsigned long long int a, unsigned long long int b)
{
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}
unsigned long long int logarithm(unsigned long long int a, unsigned long long int n)
{
    if (power(a, 1) > n)
        return 0;
    return 1 + logarithm(a, n / a);
}
int main()
{
    int tc;
    unsigned long long int a, n;
    scanf("%d", &tc);
    for (int i = 1; i <= tc; i++)
    {
        scanf("%llu %llu", &a, &n);
        printf("Case #%d: %llu\n", i, logarithm(a, n));
    }
    return 0;
}