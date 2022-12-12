#include <stdio.h>
#include <math.h>

unsigned long long int solve(unsigned long long int A, unsigned long long int N) {
  unsigned long long int B = 0;
  while (pow(A, B) < N) {
    B = B + 1;
  }
  return B - 1;
}

int main() {
    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        unsigned long long int x, y;
        scanf("%llu %llu", &x, &y);

        printf("Case #%d: %llu\n", i + 1, solve(x, y));

    }

}