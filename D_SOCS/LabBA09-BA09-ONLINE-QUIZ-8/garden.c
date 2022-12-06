#include <stdio.h>

int main(){

    int x, y;
    scanf("%d %d", &x, &y);
    int garden[x][y];
    int changes, px, py, new;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            scanf("%d", &garden[i][j]);
        }
    }
    scanf("%d", &changes);
    for(int i = 0; i < changes; i++){
        scanf("%d %d %d", &px, &py, &new);
        garden[px - 1][py - 1] = new;
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(j == y - 1) printf("%d", garden[i][j]);
            else printf("%d ", garden[i][j]);
        }
        puts("");
    }
    return 0;
}