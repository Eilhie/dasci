#include <stdio.h>

int main() {
    FILE * fp;
    fp = fopen("testdata.in", "r");
    int size;
    char log;
    int longestlog = 0;
    int logscount = 0;
    fscanf(fp, "%d", & size);
    fgetc(fp);
    while (size >= 0) {
        log = fgetc(fp);
        if (log == '1') {
            logscount++;
        } else {
            if (longestlog < logscount) 
                longestlog = logscount;
            
            logscount = 0;
        }
        size--;
    }
    
    printf("%d\n", longestlog);
    fclose(fp);
    return 0;
}