#include <stdio.h>
 
int main(){
    int M, N, a;
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        scanf(" %d", &N);
        char list[N][N];
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if((j+k)%2==1){
                    list[j][k] = '#';
                }else{
                    list[j][k] = '*';
                }
            }
        }
        for(int j=0; j<N; j++){
            int a = (N-(j+1));
            for(int k=0; k<a; k++){
                list[j][k] = ' ';
            }
        }
        printf("Case #%d:\n", i+1);
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                if(k == N-1){
                    printf("%c\n", list[j][k]);
                }else{
                    printf("%c", list[j][k]);
                }
            }
        }
    }
}