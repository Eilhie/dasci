#include <stdio.h>

int main() {
    FILE *input_file = fopen("testdata.in", "r");
    int n, m, k;
    fscanf(input_file, "%d %d", &n, &m);
    int current_page = 0;
    char line[51];
    for (int i = 0; i < m; i++) {
        fscanf(input_file, "%s", line);
        if (line[0] == '#') {
            current_page++;
            if (current_page == k) {
                break;
            }
        } else if (current_page == k) {
            printf("%s\n", line);
        }
    }
    fscanf(input_file, "%d", &k);
    fclose(input_file);
    return 0;
}
