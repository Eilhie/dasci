#include <stdio.h>

int jojonaci(int fk, int f0, int f1){
    if(fk == 0) return f0;
    else if (fk == 1) return f1;

    int t1 = f0, t2 = f1;
    int nextTerm = t2 - t1;
    
    for (int i = 1; i < fk; i++) {
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t2 - t1;
    }
    return t2;
}

int main(){
    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        int f0,f1, fk;
        scanf("%d %d %d", &fk, &f0, &f1);
        printf("Case #%d: %d\n",i + 1, jojonaci(fk, f0, f1));
    }
    
    return 0;
}
