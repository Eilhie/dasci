#include <stdio.h>

int main(){

    int lenght;
    scanf("%d", &lenght);
    long int element[lenght];
    for(int i = 0; i < lenght; i++){
        scanf("%ld", &element[i]);
    }
    int changes;
    scanf("%d", &changes);

    long int index, newprice;

    for(int j =0; j < changes; j++){
        scanf("%ld %ld", &index, &newprice);
        printf("Case #%d: ", j + 1);
        element[index-1] = newprice;
        for(int k = 0; k < lenght; k++){
            
            if(k == lenght-1){
                printf("%d", element[k]);
            } else{
                printf("%d ", element[k]);
            }
        }
        printf("\n");
    }

    return 0;
}