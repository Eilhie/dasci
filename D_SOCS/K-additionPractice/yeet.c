#include <stdio.h>

int main(){
    char string[4][150];
    for(int i = 0; i < 4; i++){
        
        scanf("%s", string[i]); getchar();
    }
    for(int i = 0; i < 4; i++){
        printf("Yeet %s \(^-^)\n", string[i]);
    }

    return 0;
}