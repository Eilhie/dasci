#include <stdio.h>
#include <string.h>

int main(){

    int numCases;
    
    scanf("%d", &numCases);
    char list[numCases][100];
    for(int i = 0; i < numCases; i++){
        scanf("%s", list[i]);
    }
    for(int i = 0; i < numCases; i++){
        printf("Case #%d: %d\n", i+1, strlen(list[i]));
    }

    return 0;
}