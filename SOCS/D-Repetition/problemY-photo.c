#include <stdio.h>

void print_rectangle(int n, int m){
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (i==1 || i==n || j==1 || j==m)           
                printf("#");           
            else
                printf(" ");           
        }
        printf("\n");
    }
 
}

int main(){
    int i, j, k, testCases;

    
    scanf("%d", &testCases);
    int list[testCases][testCases];
    for(int i = 0; i<testCases; i++){
        scanf("%d %d", &list[i][0], &list[i][1]);
    }
    for(i = 0; i < testCases; i++){
        printf("Case #%d:\n", i+1);
        print_rectangle(list[i][0], list[i][1]);
        
    }

    return 0;
}