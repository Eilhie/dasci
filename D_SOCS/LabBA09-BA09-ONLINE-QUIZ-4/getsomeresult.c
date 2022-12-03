#include <stdio.h>

int main(){
    int T, N;
    scanf("%d", &T);
    for(int i = 0; i<T; i++){
        scanf(" %d", &N);
        int matrix1[N][N];
        for(int j = 0; j<N; j++){
            for(int k = 0; k<N; k++){
                scanf(" %d", &matrix1[j][k]);
            }
        }
        int matrix2[N][N];
        for(int j = 0; j<N; j++){
            for(int k = 0; k<N; k++){
                scanf(" %d", &matrix2[j][k]);
            }
        }
        int matrix3[N][N];
        for(int j = 0; j<N; j++){
            for(int k = 0; k<N; k++){
                scanf(" %d", &matrix3[j][k]);
            }
        }

        // perkalian
        int matrixa[N][N];
        for(int j = 0; j<N; j++){
            for(int k = 0; k<N; k++){
                matrixa[j][k] = 0;
                for(int l = 0; l<N; l++){
                    matrixa[j][k]+=matrix1[j][l]*matrix2[l][k];
                }
            }
        }

        int matrixtotal[N][N];
        for(int j = 0; j<N; j++){
            for(int k = 0; k<N; k++){
                matrixtotal[j][k] = 0;
                for(int l = 0; l<N; l++){
                    matrixtotal[j][k]+=matrixa[j][l]*matrix3[l][k];
                }
            }
        }

        printf("Case #%d:\n", i+1);
        for(int j = 0; j<N; j++){
            for(int k = 0; k<N; k++){
                if(k == N-1){
                    printf("%d\n", matrixtotal[j][k]);
                }else{
                    printf("%d ", matrixtotal[j][k]);
                }
            }
        }
    }

}