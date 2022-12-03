#include <stdio.h>

int main(){
    int lenght;
    scanf("%d", &lenght);
    int list[lenght];
    for(int i = 0; i < lenght; i++){
        scanf("%d", &list[i]);
    }

    for(int i = 0; i < lenght; i++){
        if(list[i+1] == 1){
            printf("%d ", list[i]);
        }
    }
    printf("%d\n", list[lenght-1]);
    return 0;k
}