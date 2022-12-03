#include <stdio.h>

int main(){

    int N;
    scanf("%d", &N);

    double X[3];
    double Z[N];
    char name[3][10] = {"Jojo", "Lili", "Bibi"};

    scanf("%lf %lf %lf", &X[0], &X[1], &X[2]);
    for(int i = 0; i < N; i++){
        scanf("%lf", &Z[i]);
    }

    double average = X[0] + X[1] + X[2];

    for(int i = 0; i < N; i++){
        average += Z[i];
    }
    average = average/(3+N);

    for(int i = 0; i < 3; i++){
        if(X[i] >= average){
            printf("%s lolos\n", name[i]);
        }else{
            printf("%s tidak lolos\n", name[i]);
        }
    }

    return 0;
}