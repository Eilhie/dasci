#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){

        int N, G;
        scanf("%d %d", &N, &G);
        int pass[N], key[G];
        for (int j = 0; j < N; j++){
            scanf("%d", &pass[j]);
        }
        for (int j = 0; j < G; j++){
            scanf("%d", &key[j]);
        }

        int a = 0, b = G; 
        int total;
        for(int j = G - 1; j < N; j++){
            total = 0;
            for(int k = a, l = 0; k < b, l < G; k++, l++){
                total += (pass[k]^key[l]);
            } 
            
            a++;
            b++;
            printf("%d ", total);
        }
        

        // printf("Case #%d: \n", i + 1);
    }

    return 0;
}