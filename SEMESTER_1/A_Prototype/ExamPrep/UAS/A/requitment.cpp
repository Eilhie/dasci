#include <stdio.h>
#include <string.h>

struct requitments {
    char id[11];
    char name[55];
    char major[33];
    float gpa;
    char posisition[33]; 
};


int main(){
    int n, t, count = 0;
    scanf("%d", &n); getchar();
    requitments req[n];
    for(int i = 0; i < n; i++){
        scanf("%[^\n]", req[i].id); getchar();
        scanf("%[^\n]", req[i].name); getchar();
        scanf("%[^\n]", req[i].major); getchar();
        scanf("%f", &req[i].gpa); getchar();
        scanf("%[^\n]", req[i].posisition); getchar();
    }
    char major[33], position[33];
    float mingpa;
    scanf("%d", &t); getchar();
    for(int j = 1; j <= t; j++){
        scanf("%s %s %f", position, major, &mingpa);
        for(int i = 0; i < n; i++){
            if(strcmp(req[i].posisition, position) == 0 && strcmp(major, req[i].major) == 0 && req[i].gpa >= mingpa)
                count++;
        }
        printf("Case #%d: %d\n", j, count);
    }
    
    return 0;
}