#include <stdio.h>

int main(){

    int testCases;
    int list[testCases];
    int ans;
    int jump;
    int start;

    scanf("%d", &testCases);

    for(int i = 0; i < testCases; i++){
        scanf("%d", &list[i]);
    }   
    
    for(int i = 0; i < testCases; i++){
    	start = 0;
    	jump = 1;
        for(int j = 0; j <= list[i]; j++){
            if(start >= list[i]){
                printf("Case #%d: %d\n", i + 1, j);
                break;
            }
            start = start + jump;
            jump = jump + 1;
        }
    }

    return 0;
}