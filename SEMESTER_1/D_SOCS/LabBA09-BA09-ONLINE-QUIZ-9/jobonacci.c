#include <stdio.h>

int jobonaci(int fk){
    if(fk == 0) return 0;
    else if (fk == 1) return 1;
    else if (fk == 2) return 1;
    
    return (jobonaci(fk - 1) + jobonaci(fk - 3));
}

int main(){

    int fk;
    scanf("%d", &fk);
    printf("%d\n", jobonaci(fk));

    return 0;
}
