#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    int arr[6];
    for(int i = 0; i < testCases; i++){
        for(int j = 0; j < 6; j++){
            scanf("%d", &arr[j]);
        }
        printf("Case #%d: ", i+1);
        for (int fora = 0; fora < arr[0]; fora++){
            printf("a");
        }
        for (int forb = 0; forb < arr[1]; forb++){
            printf("s");
        }
        for (int forc = 0; forc < arr[2]; forc++){
            printf("h");
        }
        for (int ford = 0; ford < arr[3]; ford++){
            printf("i");
        }
        for (int fore = 0; fore < arr[4]; fore++){
            printf("a");
        }
        for (int forf = 0; forf < arr[5]; forf++){
            printf("p");
        }
        printf("\n");
    }

    return 0;
}