#include <stdio.h>

int main(){
    
    int testCases;
    scanf("%d", &testCases);

    for(int i = 0; i < testCases; i++){
        int num;
        scanf("%d", &num);

        printf("Case #%d: ", i + 1);

        for(int j = 0; j < num; j++){
            printf("%c", j + 97);
        }
        printf("\n");
    }

    return 0;
}