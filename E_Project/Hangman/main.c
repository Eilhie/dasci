#include <stdio.h>

char *input = "aaaaaaaaa";
int size = 9;

void draw(){
    for(int i = 1; i < size; i++){
        if(i % 3 == 0) printf("%c\n", input[i]);
        else printf("%c ", input[i]);
    }
}

int main(){
    draw();
    return 0;
}