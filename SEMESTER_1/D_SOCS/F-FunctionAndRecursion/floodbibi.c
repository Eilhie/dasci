#include <stdio.h>

int floodbibi(char a){
    if(a == '.') return 1;
    return 0;
}
    

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        char matrix[101][101];
        int n,m;
        scanf("%d %d", &n, &m);
        int count = 0;

        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                scanf(" %c", &matrix[j][k]);
                count += floodbibi(matrix[j][k]);
            }
        }

        printf("Case #%d: %d\n", i + 1, count);
    }

    return 0;
}
