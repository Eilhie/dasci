#include <stdio.h>

int main(){

    int repeat, rows;
    scanf("%d %d", &repeat, &rows);

    int i, j, k;   
    for(int x = 0; x < repeat; x++){
        for (i = 1; i <= rows; i++){  
            for (j = i; j < rows; j++)  
            {  
                printf(" ");   
            }  
            for (k = 1; k <= i; k++)  
            {  
                printf("*"); // print the Star  
            }  
            printf ("\n");   
        } 
    }
     

    return 0;
}