#include <stdio.h>

void swap(char *a, char *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int changes;
        char string[1010];
        scanf("%d %s", &changes, string);
        for(int l = 0; l < changes; l++){
            int index, index2;
            scanf("%d %d", &index, &index2);
            for(int j = index - 1, k = index2 - 1; j <= k, k >= j; j++, k--){
                swap(&string[j], &string[k]);
            }
        }
        printf("Case #%d: %s\n", i + 1, string);
    }

    return 0;
}