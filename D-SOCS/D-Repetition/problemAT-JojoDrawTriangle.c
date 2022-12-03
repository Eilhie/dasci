#include <stdio.h>  

int main()  {  
    
    int testCase;
    scanf("%d", &testCase);

    int i, j, rows[testCase], star = 0;  
    for(int x = 0; x < testCase; x++){
        scanf ("%d", &rows[x]);   
    }
    for(int x = 0; x < testCase; x++){    
        for (i = 0; i < rows[x]; i++) {
            for (j = 1; j <= (rows[x] - i - 1); j++) {
                printf(" ");
            }
            while (star != (2 * i + 1)) {
                printf("*");
                star++;;
            }
            star = 0;
            printf("\n");
        }
    }
    

    return 0;
}  