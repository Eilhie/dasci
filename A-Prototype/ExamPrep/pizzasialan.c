#include <stdio.h>
#include <math.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int cut;
        scanf("%d", &cut);

        printf("Case #%d: %d\n", i + 1, (cut*cut + cut + 2) / 2);

    }

    return 0;
}