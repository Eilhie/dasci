#include <stdio.h>

int main(){

    char name1[100],name2[100];
    double tinggi1,tinggi2;
    int umur2,umur1;
    scanf("%s %lf %d %s %lf %d", name1, &tinggi1,&umur1, name2, &tinggi2, &umur2);
    printf("Name 1: %s\n", name1);
    printf("Height 1: %.2f\n", tinggi1);
    printf("Age 1: %d\n", umur1);
    printf("Name 2: %s\n", name2);
    printf("Height 2: %.2f\n", tinggi2);
    printf("Age 2: %d\n", umur2);

    return 0;
}

