#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int cut;
        scanf("%d", &cut);

        printf("Case %d:", i + 1);
        for(int j = 0; j < cut; j++){
            printf(" %d", (j*j + j + 2) / 2);
        }
        puts("");
    }

    return 0;
}