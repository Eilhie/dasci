#include <stdio.h>

int main() {
    int T, N, Q, L, R, sum;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        scanf("%d", &N);

        int A[N+1], prefixSum[N+1];
        prefixSum[0] = 0;

        for (int j = 1; j <= N; j++) {
            scanf("%d", &A[j]);
            prefixSum[j] = prefixSum[j-1] + A[j];
        }

        scanf("%d", &Q);
        printf("Case #%d:\n", i);
        for (int j = 1; j <= Q; j++) {
            scanf("%d %d", &L, &R);
            sum = prefixSum[R] - prefixSum[L-1];
            printf("%d\n", sum);
        }
    }
    return 0;
}
