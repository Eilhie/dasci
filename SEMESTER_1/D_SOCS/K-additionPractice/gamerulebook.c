#include <stdio.h>

int main() {
    FILE *fp = fopen("testdata.in", "r");
    int n, m, k;
    fscanf(fp, "%d %d", &n, &m); fgetc(fp);
    char line[n][100000];
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%[^#]#", line[i]); fgetc(fp);
    }
    fscanf(fp, "%d", &k); fgetc(fp);
    fclose(fp);
    printf("%s", line[k-1]);
    
    return 0;
}

