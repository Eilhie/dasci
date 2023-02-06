#include <stdio.h>
#include <stdlib.h>

int count_demolished_buildings(int n, char **grid) {
    int demolished = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'T') {
                if (i > 0 && grid[i-1][j] == 'o') {
                    demolished++;
                }
                if (i < n-1 && grid[i+1][j] == 'o') {
                    demolished++;
                }
                if (j > 0 && grid[i][j-1] == 'o') {
                    demolished++;
                }
                if (j < n-1 && grid[i][j+1] == 'o') {
                    demolished++;
                }
                if (i > 0 && j > 0 && grid[i-1][j-1] == 'o') {
                    demolished++;
                }
                if (i > 0 && j < n-1 && grid[i-1][j+1] == 'o') {
                    demolished++;
                }
                if (i < n-1 && j > 0 && grid[i+1][j-1] == 'o') {
                    demolished++;
                }
                if (i < n-1 && j < n-1 && grid[i+1][j+1] == 'o') {
                    demolished++;
                }
            }
        }
    }
    return demolished;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    char **grid;
    grid = (char**)malloc(n*sizeof(char*));
    printf("Enter the grid of characters (use '.' for empty space, 'o' for building, and 'T' for explosive):\n");
    for (int i = 0; i < n; i++) {
        grid[i] = (char*)malloc(150*sizeof(char));
        for (int j = 0; j < n; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }
    printf("Total number of demolished buildings: %d\n", count_demolished_buildings(n, grid));
    return 0;
}
