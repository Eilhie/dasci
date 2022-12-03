#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);

    for(int i = 0; i < testCases; i++){
        int sudoku[9][9];
        for(int j = 0; j < 9; j++){
            for(int k = 0; k < 9; k++){
                scanf("%d", &sudoku[j][k]);
            }
        }
        int checkedx = 0;
        int checkedy = 0;
        for(int z = 0; z < 9; z++){
            int sum = 0;
            for(int j = 0; j < 9; j++){
                sum += sudoku[z][j];
                if(sum == 45){
                    checkedx++;
                }
            }
            sum = 0;
            for(int k = 0; k < 9; k++){
                sum += sudoku[k][z];
                if(sum == 45){
                    checkedy++;
                } 
            }
        }
        // printf("%d %d \n", checkedx, checkedy);
        if(checkedx == checkedy){
            printf("Case #%d: True\n", i + 1);
        } else {
            printf("Case #%d: False\n", i + 1);
        }
        
    }

    return 0;
}