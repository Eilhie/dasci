#include<stdio.h>
#include<string.h>

struct student{
    char id[21];
    char name[101];
    char score[3];
};

int main(){
    int n;
    scanf("%d", &n);
    struct student students[n];
    for(int i=0; i<n; i++){
        scanf("%s", students[i].id); getchar();
        scanf("%[^\n]", students[i].name); getchar();
        scanf("%s", students[i].score); getchar();
    }
    int q;
    scanf("%d", &q); getchar();
    for(int i=1; i<=q; i++){
        int x;
        scanf("%d", &x); getchar();
        printf("Query #%d:\n", i);
        printf("ID: %s\n", students[x-1].id);
        printf("Name: %s\n", students[x-1].name);
        printf("Score: %s\n", students[x-1].score);
    }
    return 0;
}
