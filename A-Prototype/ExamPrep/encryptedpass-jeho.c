#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        int N, G;
        scanf(" %d %d", &N, &G);
        int array[99], key[99];
        for(int j=0; j<N; j++){
            scanf(" %d", &array[j]);
        }
        for(int j=0; j<G; j++){
            scanf(" %d", &key[j]);
        }
        int a=0, b=G;
        for(int j=G-1; j<N; j++){
            int total=0;
            for(int k=a, l=0; k<b, l<G; k++, l++){
                total+=(array[k]^key[l]);      
            }
            a++;
            b++;
            printf("%d ", total); 
        }
        printf("\n");
    }
}
