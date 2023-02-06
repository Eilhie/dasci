#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long int factorial(int n) {
  if (n == 0 || n == 1) return 1;
  return (n * factorial(n - 1)) % MOD;
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 1; i <= t; i++) {
    int n; 
    scanf("%d", &n);

    long long int product = 1; 

    for (int j = 0; j < n; j++) {
      int a; 
      scanf("%d", &a);
      product = (product * factorial(a)) % 1000000007;
    }

    printf("Case #%d: %lld\n", i, product);
  }

  return 0;
}
