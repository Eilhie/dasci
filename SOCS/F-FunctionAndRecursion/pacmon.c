#include<stdio.h> 
#include<stdlib.h>  

int result;  

void countFood(char** matrix, int i, int j, int row, int col, int** visited){      

    if(i<0 || j<0 || i>=row || j>=col || matrix[i][j]=='#' || visited[i][j]==1)         
        return;     
    if(matrix[i][j] == '*')         
        result++;      

    visited[i][j] = 1;      
    
    int X[] ={0,0,1,-1};     
    int Y[] ={1,-1,0,0};      
      
    for(int k=0; k<4; k++){
        countFood(matrix,i+X[k],j+Y[k],row,col,visited);
    } 
}  

int main(){     
    int T;      
    scanf(" %d",&T);      
    for(int t=1; t<=T; t++){         
        int row,col;
        scanf(" %d",&row);         
        scanf(" %d",&col);          
        char** matrix;   
        int** visited;          
        matrix = (char**)malloc(row*sizeof *matrix);         
        visited =  (int**)malloc(row*sizeof *visited);          
        for(int i=0; i<row; i++){
            matrix[i]= (char*)malloc(col*sizeof *matrix[i]);             
            visited[i]= (int*)malloc(col*sizeof *visited[i]);
        }
        int startX = -1;         
        int startY = -1;               
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                visited[i][j]=0;
                scanf(" %c", &matrix[i][j]);
                if(matrix[i][j]=='P'){
                    startX = i;
                    startY = j;
                }
            }
        }         
        result = 0;          
        countFood(matrix,startX,startY,row,col,visited);    
        printf("Case #%d: %d\n",t,result);
    }    
}