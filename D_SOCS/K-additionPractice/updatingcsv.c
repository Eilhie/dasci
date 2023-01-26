#include <stdio.h>
#include <string.h>

#define MAX_ROW 100
#define MAX_COL 10
#define MAX_CELL_LEN 5

int main() {
    int n, m, q, x;
    char csv[MAX_ROW][MAX_COL][MAX_CELL_LEN];
    char h[MAX_CELL_LEN], s[MAX_CELL_LEN];
    FILE *file = fopen("testdata.in", "r");

    // Read the number of rows and columns
    fscanf(file, "%d %d", &n, &m);

    // Read the CSV file
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            fscanf(file, "%s", csv[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%s", csv[i][j]);
        }
        puts("");
    }
    // Read the number of queries
    fscanf(file, "%d", &q);

    // Perform the queries
    for(int i = 0; i < q; i++) {
        fscanf(file, "%d %s %s", &x, h, s);
        x--; // Convert the row number to zero-based index

        // Find the column with the header h
        for(int j = 0; j < m; j++) {
            if(strcmp(csv[0][j], h) == 0) {
                // Update the cell in the x-th row with the new data s
                strcpy(csv[x][j], s);
                break;
            }
        }
    }

    // Print the updated CSV file
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%s", csv[i][j]);
            if(j < m-1) printf(";");
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}
