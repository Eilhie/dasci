#include<stdio.h>
#include<string.h>

struct course{
    char code[9];
    char day[11];
    int time;
};

int main(){
    int n;
    scanf("%d", &n); getchar();
    struct course courses[n];
    for(int i=0; i<n; i++){
        scanf("%s", courses[i].code); getchar();
        scanf("%s", courses[i].day); getchar();
        scanf("%d", &courses[i].time); getchar();
    }
    int q;
    scanf("%d", &q);
    for(int i=1; i<=q; i++){
        int x;
        scanf("%d", &x); getchar();
        printf("Query #%d:\n", i);
        printf("Code: %s\n", courses[x-1].code);
        printf("Day: %s\n", courses[x-1].day);
        printf("Time: %02d:00\n", courses[x-1].time);
    }
    return 0;
}
