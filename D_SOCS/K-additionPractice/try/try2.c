#include <stdio.h>

int main(){
    char filename[100];
    fscanf(filename, "%s", &n); getchar();
    FILE *fp = fopen(filename, "w");
    
    if(fp == NULL) {
        printf("File not found\n");
    }
    for(int i = 0; i < n; i++) {
        char str[201];
        int a, b;
        scanf("%[^\n]", str); getchar();
        fprintf(fp, str);
    }
    
    fclose(fp);
    return 0;
}