#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);

    for(int i = 0; i < testCases; i++){
        int size;
        scanf("%d", &size);
        long long int matrix[size][size];
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                scanf("%d", &matrix[j][k]);
            }
        }
        printf("Case #%d: ", i + 1);
        long long int total[size];
        for(int j = 0; j < size; j++){
            total[j] = 0;
            for(int k = 0; k < size; k++){
                total[j] += matrix[k][j];
            }
            if(j == size - 1){
                printf("%d\n", total[j]);
            } else{
                printf("%d ", total[j]);
            }
           
        }
    }

    return 0;
}