#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    file = fopen("testdata.in", "r");
    int T;
    fscanf(file, "%d\n", &T);
    for(int i=0; i<T; i++){
        int N;
        fscanf(file, "%d\n", &N);
        int list[100];
        int total=0;
        for(int j=0; j<N; j++){
            fscanf(file, "%d\n", &list[j]);
            total+=list[j];
        }
        int Area=total*4;
        int Perimeter=N*4+(list[0]+list[N-1])*2;
        for(int j=0; j<N-1; j++){
            Perimeter=Perimeter+(abs(list[j]-list[j+1])*2);
        }
        printf("Case #%d: %d %d\n", i+1, Perimeter, Area);
    }
}