#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);

    for(int i = 0; i < testCases; i++){
        int N; 
        scanf("%d", &N);
        long long int matrix[N][N];
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                scanf("%lld", &matrix[j][k]);
            }
        }
        long long int sum[N];
        printf("Case #%d:", i + 1);
        for(int j = 0; j < N; j++){
            sum[j] = 0;
            for(int k = 0; k < N; k++){
                sum[j] += matrix[k][j];
            }
            
            printf(" %lld", sum[j]);
        }
        printf("\n");
    }

    return 0;
}