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
        long long int min = abs(list[0]-list[1]);
        for(int j=1; j<N; j++){
            if(min>=abs(list[j]-list[j+1])){
                min = abs(list[j]-list[j+1]);
            }
        }
        printf("Case #%d: %lld\n", i+1, min);
    }
}