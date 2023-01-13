#include<stdio.h>

int visited[8][8];

void ffl(int step, int xpos, int ypos, int xdes, int ydes){
    if(xpos < 0 || ypos < 0 || xpos > 7 || ypos > 7 || visited[ypos][xpos] <= step){
        return;
    }

    visited[ypos][xpos] = step;

    int x[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int y[] = {2, -2, 2, -2, 1, -1, 1, -1};
    for(int i=0; i<8; i++){
        ffl(step+1, xpos+x[i], ypos+y[i], xdes, ydes);
    }
}

int main(){
    int T, White_PosX, White_PosY, Black_PosX, Black_PosY;
    char whitec, blackc;
    scanf("%d", &T);
    for(int i = 0; i<T; i++){
        for(int j=0; j<8; j++){
            for(int k=0; k<8; k++){
                visited[j][k]=64;
            }
        }

        scanf(" %c%d %c%d", &whitec, &White_PosY, &blackc, &Black_PosY);
        
        White_PosX = whitec - 'A';
        Black_PosX = blackc - 'A';
        White_PosY = 8 - White_PosY;
        Black_PosY = 8 - Black_PosY;
        
        ffl(0, White_PosX, White_PosY, Black_PosX, Black_PosY);
        
        printf("Case #%d: %d\n", i+1, visited[Black_PosY][Black_PosX]);
    }
}