#include <stdio.h>

void weirdShape(int N){
    int i,j;
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            if(i==1 || i==N || j==1 || j==N || i==j || j==(N - i + 1)){
                printf("*");
            }
            else{
                printf(" ");
            }
        }

        printf("\n");
    }
}

int main(){

    int i,testCases;

    
    scanf("%d", &testCases);
    int list[testCases];
    for(int i = 0; i<testCases; i++){
        scanf("%d", &list[i]);
    }
    for(i = 0; i < testCases; i++){
        weirdShape(list[i]);
        printf("\n");
    }

    return 0;
}