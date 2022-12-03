#include <stdio.h>
#include <string.h>

int main(){

    int R, C;
    scanf("%d %d", &R, &C);
    char matrix[R][210];
    char temp[210];
    for(int i = 0; i < R; i++){
        scanf("%s", &matrix[i]);
    }

    puts("");
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            for(int k = 0; k < (C - 1); k++){
                if(matrix[i][k] > matrix[i][k + 1]){
                    strcpy(temp, (char)matrix[i][k]);
                    matrix[i][k] = matrix[i][k + 1];
                    strcpy((char)matrix[i][k + 1], temp);
                }
            }
        }
    }

    for(int i = 0; i < R; i++){
        printf("%s", matrix[i]);
        puts("");
    }

    return 0;
}