// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//     int size;
//     char string[35];
//     scanf("%d %s", &size, string); getchar();
//     char** matrix;           
//     matrix = (char**)malloc(size*sizeof *matrix);                   
//     for(int i=0; i<size; i++) {
//         matrix[i]= (char*)malloc(35*sizeof *matrix[i]);      
//         scanf("%[^\n]", matrix[i]); getchar();
//     }     
//     for(int i=0; i<size; i++) {
//         printf("%s\n", matrix[i]);
//     }
// }

#include <stdio.h>
#include <string.h>

#define MAX_N 30

int n;
char word[MAX_N+1];
char grid[MAX_N][MAX_N+1];

int main() {
    scanf("%d %s", &n, word);
    for (int i = 0; i < n; i++) scanf("%s", grid[i]);

    // check horizontally left to right
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n-strlen(word); j++) {
            if (strncmp(grid[i]+j, word, strlen(word)) == 0) {
                printf("YES\n");
                return 0;
            }
        }
    }

    // check horizontally right to left
    for (int i = 0; i < n; i++) {
        for (int j = n-strlen(word); j >= 0; j--) {
            if (strncmp(grid[i]+j, word, strlen(word)) == 0) {
                printf("YES\n");
                return 0;
            }
        }
    }

    // check vertically top to bottom
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= n-strlen(word); i++) {
            int match = 1;
            for (int k = 0; k < strlen(word); k++) {
                if (grid[i+k][j] != word[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("YES\n");
                return 0;
            }
        }
    }

    // check vertically bottom to top
    for (int j = 0; j < n; j++) {
        for (int i = n-strlen(word); i >= 0; i--) {
            int match = 1;
            for (int k = 0; k < strlen(word); k++) {
                if (grid[i+k][j] != word[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}