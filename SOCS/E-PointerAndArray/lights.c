#include <stdio.h>

int main(){
    int testCases;
    scanf("%d", &testCases);
    for(int main = 1; main <= testCases; main++){
        int N, M, Q;
        scanf("%d %d %d", &N, &M, &Q);
        int pattern[N][M];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                scanf("%d", &pattern[i][j]);
            }
        }
        int friends[Q];
        for(int i = 0; i < Q; i++){
            scanf("%d", &friends[i]);
        }

        printf("Case #%d:\n", main);

        int lights[M];
        for(int i = 0; i < M; i++){
            lights[i] = 0;
        }
        for(int j = 0; j < Q; j++){
            for(int i = 0; i < M; i++){
                if(lights[i] == 0){
                    lights[i] = pattern[friends[j]-1][i];
                } else if(lights[i] == 1 && pattern[friends[j]-1][i]){
                    lights[i] = 0;
                }
            }
        }
        for(int i = 0; i < M; i++){
            if(lights[i] == 0){
                printf("NO\n");
            } else{
                printf("YES\n");
            }
        }
    }
}