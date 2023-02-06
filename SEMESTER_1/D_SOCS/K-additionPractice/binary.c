#include <stdio.h>

void binary(long long int n)
{
    int binaryNum[105];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%lld", binaryNum[j]);puts("");
}

int main()
{
    long long int n,tc;
    scanf("%lld",&tc);
    for(long long int i = 0; i < tc; i++){
        scanf("%lld", &n);
        printf("Case #%lld: ",i+1);
        binary(n);
    }
    return 0;
}