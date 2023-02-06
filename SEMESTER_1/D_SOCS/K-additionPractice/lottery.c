#include <stdio.h>

int N;
int A[10004];
int odd_count[100004];
int even_count[100004];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        if (A[i] % 2 == 0) {
            even_count[i] = even_count[i - 1] + 1;
            odd_count[i] = odd_count[i - 1];
        } else {
            odd_count[i] = odd_count[i - 1] + 1;
            even_count[i] = even_count[i - 1];
        }
    }
    int Q;
    scanf("%d", &Q);
    for (int t = 1; t <= Q; t++) {
        int M;
        scanf("%d", &M);
        int odd_parity = 0, even_parity = 0;
        for (int i = 1; i <= N; i++) {
            if (A[i] < M) continue;
            if (A[i] % 2 == 0) {
                even_parity += even_count[i - 1];
            } else {
                odd_parity += odd_count[i - 1];
            }
        }
        printf("Case #%d: %d %d\n", t, odd_parity, even_parity);
    }
    return 0;
}
