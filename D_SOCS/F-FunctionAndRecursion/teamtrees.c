#include <stdio.h>

void teamTrees(int t){
    int len;
        scanf("%ld", &len);
        int arr;
        int total = 0;
        for(int i = 0; i < len; i++){
            scanf("%d", &arr);
            total += arr;
        }
        printf("Case #%d:", t + 1);
        printf(" %d\n", total);
}

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        teamTrees(i);
    }

    return 0;
}