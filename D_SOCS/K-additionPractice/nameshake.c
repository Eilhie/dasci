#include<stdio.h>
#include<string.h>

struct student{
    char first_name[16];
    char last_name[16];
};

int main(){
    int n;
    scanf("%d", &n);
    struct student students[n];
    for(int i=0; i<n; i++){
        scanf("%s %s", students[i].first_name, students[i].last_name);
    }
    int count = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(students[i].first_name, students[j].first_name)==0 && strcmp(students[i].last_name, students[j].last_name)==0){
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
