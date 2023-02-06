#include <stdio.h>

int main(){

    int testCases;
    scanf("%d", &testCases);

    for(int i = 0; i < testCases; i++){
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int arr;
        for (int j=0; j < n; j++){
            
            scanf("%d", &arr); getchar();    
                
            if(arr>=k && arr<=m){
             k= arr;
            }
            
        }
        
        printf("Case #%d: %d\n", i + 1, k);
    }

    return 0;
}