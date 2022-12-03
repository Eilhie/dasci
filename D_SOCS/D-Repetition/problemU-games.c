#include <stdio.h>

int main(){

    int testCases;
    
    scanf("%d", &testCases);

    int game[testCases];
    char list[testCases][100];
    int lili[testCases], bibi[testCases];

    for(int i = 0; i < testCases; i++){
        scanf("%d", &game[i]);
        scanf("%s", list[i]);
    }

    for(int i = 0; i < testCases; i++){
        lili[i] = 0;
        bibi[i] = 0;
        for(int j = 0; j < game[i]; j++){
            
            if(list[i][j] == 'L'){
                lili[i] = lili[i] + 1;
            }else if(list[i][j] == 'B'){
                bibi[i] = bibi[i] + 1;
            }
        }
        if(lili[i] == bibi[i]){
            printf("None\n");
        }else if(bibi[i] > lili[i]){
            printf("Bibi\n");
        }else if(lili[i] > bibi[i]){
            printf("Lili\n");
        }else {
            printf("None\n");
        }
    }

    return 0;
}