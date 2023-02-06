#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void minstep(int step, int xpos, int ypos, int xdes, int ydes, char **grid, int **visited, int horlimit, int verlimit){
    if(xpos < 0 || ypos < 0 || xpos > horlimit|| ypos > verlimit || visited[ypos][xpos] <= step || grid[ypos][xpos] == '#'){
        return;
    }
    visited[ypos][xpos] = step;
    int x[] = {1, -1, 0, 0};
    int y[] = {0, 0, 1, -1};
    for(int i=0; i<4; i++){
        minstep(step+1, xpos+x[i], ypos+y[i], xdes, ydes, grid, visited, horlimit, verlimit);
    }
}

int minpospath(int **visited, int xdes, int ydes){
    int x[] = {1, -1, 0, 0};
    int y[] = {0, 0, 1, -1};
    int steps[4];
    int min = 100000;
    int count = 0;
    for(int i = 0; i < 4; i++){
        steps[i] = visited[ydes + y[i]][xdes + x[i]];
        if(steps[i] < min) min = steps[i];
    }
    for(int i = 0; i < 4; i++){
        if(steps[i] == min) count += 1;
    }
    return count;
}

int main(){
    
    FILE *fp = fopen("mine.dig", "r");
    int endX, endY, startX, startY;
    int size = 0;
    int hlimit = 0;
    char **grid;
    int **visited;

    grid = (char**)malloc(1000000*sizeof(*grid));         
    visited = (int**)malloc(1000000*sizeof *visited);          
    while(!feof(fp)){
        grid[size]= (char*)malloc(10*sizeof(*grid[size]));
        visited[size]= (int*)malloc(7*sizeof(*visited[size]));
        fscanf(fp,"%[^\n]\n", grid[size]);    
        printf("%s\n", grid[size]);
        for(int j = 0; j < strlen(grid[size]); j++){
            visited[size][j] = 104;
            if(grid[size][j] == 'X'){
                endY = size;
                endX = j;
            } else if(grid[size][j] == '0') {
                startY = size;
                startX = j;
            }
            hlimit = strlen(grid[size]);
        }
		size+=1;
        
	}

    minstep(0, startX, startY, endX, endY, grid, visited, hlimit, size);
    printf("min steps: %d\n", visited[endY][endX]);
    printf("min pos path: %d\n", minpospath(visited,endX, endY));
    
}
