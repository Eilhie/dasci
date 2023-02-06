#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        long int len, search;
        scanf("%ld %ld", &len, &search);
        long int list;
        int count = 0;
        for(int j = 0 ; j < len; j ++){
            scanf("%ld", &list);
            if(list >= search){
                count++;
            }
        }

        printf("Case #%d: %d\n", i + 1, count);
    }

    return 0;
}