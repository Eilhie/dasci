#include <stdio.h>
#include <stdlib.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    
    for(int i = 0; i < testCases; i++){
        long int drink,empty;
        scanf("%ld %ld", &drink,&empty);
        int total = 0;
        for(int j = 0; j < 100; j++){
            int sisa;
            if(drink%empty == 0){
                sisa = drink/empty;
                drink = sisa;
                total += sisa * empty;
            }else {
                sisa = (drink-(drink%empty))/empty;
                drink = sisa + (drink%empty);
                total += sisa * empty;
            }
        }
        total += (drink%empty);
        printf("Case #%d: %d\n", i+1, total);
    }

    return 0;
}