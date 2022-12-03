#include <stdio.h>

int main(){

    int testCases; 
    scanf("%d", &testCases);

    int days;

    for(int i = 0; i < testCases; i++){
        scanf("%d", &days);

        int t1 = 0, t2 = 1;
        int nextTerm = t1 + t2;

        printf("Case #%d: ", i + 1);

        if(days == 1){
            printf("%d\n", t1);
        } else if(days == 2){
            printf("%d\n", t2);
        } else{
            int lastnum;
            for (int j = 3; j <= days; ++j){
                lastnum = nextTerm;
               
                t1 = t2;
                t2 = nextTerm;
                nextTerm = t1 + t2;
            }
            printf("%d\n", lastnum);
        }
    }

    return 0;
}