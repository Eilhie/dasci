#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int T;
    scanf(" %d", &T);
    for(int i=0; i<T; i++){
        int N;
        scanf(" %d", &N);
        long long int list[N];
        for(int j=0; j<N; j++){
            scanf(" %lld", &list[j]);
        }
        // int temp;
        // for(int j = 0; j < N; j++){
        //     for(int k = 0; k < N; k++){
        //         if(list[i] < list[k]){
        //             temp = list[i];
        //             list[i] = list[j];
        //             list[j] = temp;
        //         }
        //     }
        // }

        long long int min = abs(list[0]-list[1]);
        for(int j=1; j<N - 1; j++){
            if(min>=abs(list[j]-list[j+1])){
                min = abs(list[j]-list[j+1]);
            }
        }
        printf("Case #%d: %lld\n", i+1, min);
    }
}