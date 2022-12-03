#include <stdio.h>

int main(){

    int numCases;
    
    scanf("%d", &numCases);
    long int list[numCases][numCases+1];
    for(int i = 0; i < numCases; i++){
        scanf("%ld %ld %ld", &list[i][0], &list[i][1], &list[i][2]);
    }
    for(int i = 0; i < numCases; i++){
        if(list[i][0] <= (list[i][1] + list[i][2])){
            printf("Case #%d: yes\n", i+1);
        }else{
            printf("Case #%d: no\n", i+1);
        }
    }

    return 0;
}