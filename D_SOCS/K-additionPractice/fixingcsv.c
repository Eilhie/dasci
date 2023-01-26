#include <stdio.h>
#include <string.h>

const int MOD = 1e9 + 7;

// int main() {
    
//     int empty_cells = 0;
//     FILE* file = fopen("testdata.in", "r");
//     char line[100];
//     int row = 1, col = 1;
//     while (fgets(line, sizeof(line), file)) {
//         char* cell = strtok(line, ";");
//         while (cell != NULL) {
//             if (strcmp(cell, "") == 0) {
//                 empty_cells++;
//             }
//             cell = strtok(NULL, ";");
//         }
//     }
//     printf("%d\n", empty_cells * 101  % MOD);
//     fclose(file);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char c;
    int missing_data = 0;

    if(argc != 2) {
        printf("Usage: %s <delimiter>\n", argv[0]);
        return 1;
    }

    char delimiter = argv[1][0];

    file = fopen("testdata.in", "r");

    while((c = fgetc(file)) != EOF) {
        if (c == delimiter) {
            c = fgetc(file);
            if (c == delimiter) {
                missing_data++;
            }
        }
    }

    if(missing_data == 2 && c == EOF)
        printf("File contains only '%c\\n%c\\n'\n", delimiter, delimiter);
    else
        printf("Number of missing data: %d\n", missing_data);

    fclose(file);
    return 0;
}
