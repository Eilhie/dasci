#include <stdio.h>

int main(){

    FILE *fp  = fopen("testdata.in", "r");

    int len;
    fscanf(fp, "%d\n", &len);
    double mean = 0;
    int count;
    for(int i = 0; i < len; i++){
        fscanf(fp, "%d", &count);
        mean += count;
    }
    printf("%.2f\n", mean / len);

    return 0;
}