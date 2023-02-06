#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int len, time;
        int count = 0;
        scanf("%d %d", &len, &time);
        int train[len];
        for(int j = 0; j < len; j++){
            scanf("%d", &train[j]);
        }
        
        for(int j = 0; j < len; j++){
            for(int k = 0; k < len - 1 - j; k++){
                if(train[k] > train[k + 1]){
                    swap(&train[k], &train[k + 1]);
                    count++;
                }
            }
        }

        int totaltime = count * time;
        printf("Case #%d: %d\n", i + 1, totaltime);

    }

    return 0;
}
