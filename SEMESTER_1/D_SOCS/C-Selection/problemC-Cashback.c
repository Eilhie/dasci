#include <stdio.h>

int main(){
    int casenum;

    scanf("%d", &casenum);
    int K[casenum], N[casenum];

    for (int i = 0; i < casenum; i++) {
        scanf("%d %d", &K[i], &N[i]);
    }

    for (int i = 0; i < casenum; i++){
        if (K[i] < N[i]){
            printf("Case #%d: Bi-Pay\n", i+1);
        } else if (K[i] > N[i]){
            printf("Case #%d: Go-Jo\n", i+1);
        }else {

        }
    }

    return 0;
}