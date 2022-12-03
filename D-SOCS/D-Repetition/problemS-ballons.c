#include <stdio.h>

int main(){

    long int NumOfBallons, strenght;
    long int poped = 0;
    scanf("%ld %ld", &NumOfBallons, &strenght);
    long int list[NumOfBallons];

    for(long int i = 0; i < NumOfBallons; i++){
        scanf("%ld", &list[i]);
    }

    for(long int i = 0; i < NumOfBallons; i++){
        if(list[i] < strenght){
            poped += 1;
        }
    }

    printf("%d\n", poped);

    return 0;
}