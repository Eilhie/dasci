#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count;

void countfood(char **map, int startX, int startY, int sizeX, int sizeY,int **visited){
    if(startX < 0 || startY < 0 || startX >= sizeX || startY >= sizeY || visited[startY][startX] == 1 || map[startY][startX] == '#')
        return;

    if(map[startY][startX] == '*')
        count++;

    visited[startY][startX] = 1;

    int X[] = {1, -1, 0, 0};
    int Y[] = {0, 0, 1, -1};

    for(int i = 0; i < 4; i++){
        countfood(map, startX + X[i], startY + Y[i], sizeX, sizeY, visited);
    }
}

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int W, H;
        int posX, posY;
        scanf("%d %d", &H, &W); getchar();
        char **map;
        map = malloc(H*sizeof(char*));
        int **visited;
        visited = calloc(H, sizeof(int*));
        for(int i = 0; i < H; i++){
            map[i] = malloc(100*sizeof(char));
            visited[i] = calloc(W, sizeof(int));
            for(int j = 0; j < W; j++){
                scanf("%c", &map[i][j]);
                if(map[i][j] == 'P'){
                    posX = j;
                    posY = i;
                }
            }
            getchar();
        }
        
        count = 0;
        countfood(map, posX, posY, W, H, visited);

        printf("Case #%d: %d\n", i + 1, count);

    }

    return 0;
}



