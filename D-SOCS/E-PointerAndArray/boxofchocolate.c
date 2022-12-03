#include <stdio.h>

int main(){
    int testCases;
    scanf("%d", &testCases);

    for(int i = 0; i < testCases; i++){
        int n, m;
        scanf("%d %d", &n, &m);
        long long int matrix[n][m];
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                scanf("%lld", &matrix[j][k]);
            }
        }

        long long int max[n];    
              
        for (int j = 0; j < n; j++) {     
            max[j] = matrix[j][0];
            for(int k = 0; k < m; k++){
                if(matrix[j][k] > max[j]){
                    max[j] = matrix[j][k];
                }
            }   
        }

        long long int sum = 0;
        for(int j = 0; j < n; j++){
            sum  = sum + max[j];
        }
        printf("Case #%d: %lld\n", i + 1, sum);
    }
    return 0;
}
