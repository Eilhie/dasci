#include <stdio.h>

int main(){

    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        int lenght;
        scanf("%d", &lenght);
        int neaded[lenght], have[lenght];
        for(int j = 0; j < lenght; j++){
            scanf("%d", &neaded[j]);
        }
        for(int j = 0; j < lenght; j++){
            scanf("%d", &have[j]);
        }
        printf("Case #%d: ", i + 1);
        for(int j = 0; j < lenght; j++){
            if(k == lenght-1){
                printf("%d", neaded[j]-have[j]);
            } else{
                printf("%d ", neaded[j]-have[j]);
            }
        }
        printf("\n");
    }

    return 0;
}