/*
3
2301905050
Jojo
75
2301905000
Lili
85
2301905011
Bibi
95
*/

#include <stdio.h>

struct people {
    char nim[11];
    char name[20];
    double score;
};


int main(){
    int n;
    scanf("%d", &n); getchar();
    people peop[50000];
    double count = 0;
    for(int i = 0; i < n; i++){
        scanf("%[^\n]", peop[i].nim); getchar();
        scanf("%[^\n]", peop[i].name); getchar();
        scanf("%lf", &peop[i].score); getchar();
        count += peop[i].score;
    }
    double average = count / n;
    for (int i = 0; i < n; i++){
        if(peop[i].score >= average) 
            printf("%s %s\n", peop[i].nim, peop[i].name);
    }
    
    return 0;
}
