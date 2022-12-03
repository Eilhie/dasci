#include <stdio.h>

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    for(int i = 0; i <= y; i++){
        printf("%d\n",x+i);
    }
}