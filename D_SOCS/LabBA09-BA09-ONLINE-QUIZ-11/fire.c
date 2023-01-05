#include <stdio.h>

int main(){
    int size = 3;
    char map[3][5] = {"###", "###", "F##"};
    int x, y;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(map[i][j] == 'F') {
                x = i;
                y = j;
            }
            printf("%c", map[i][j]);
        }
        puts("");
    }

    printf("\n%d %d\n", x, y);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            
            printf("%c", map[i][j]);
        }
        puts("");
    }

    return 0;
}