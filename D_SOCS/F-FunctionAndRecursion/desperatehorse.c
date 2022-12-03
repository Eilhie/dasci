#include <stdio.h>   
#include <stdlib.h>

int chessboard[8][8]={0};   

int minimum(int a, int b){
    if(a<=b){	
        return a;
    } 	
    return b; 
}  

int countS(int startX, int startY, int targetX, int targetY){
    int min, x1, y1, x2, y2; 
    if (startX == targetX && startY == targetY){	
        return chessboard[0][0];  	
    }else{  		
        if (chessboard[abs(startX - targetX)][abs(startY - targetY)] != 0){	
            return chessboard[abs(startX - targetX)][abs(startY - targetY)];
        } else{ 
            if (startX <= targetX) {  				
                if (targetX <= targetY) {  					
                    x1 = startX + 2;  					
                    y1 = targetX + 1;  					
                    x2 = startX + 1;  					
                    y2 = targetX + 2;  				
                }else {  					
                    x1 = startX + 2;  					
                    y1 = targetX - 1;  					
                    x2 = startX + 1;  					
                    y2 = targetX - 2;
                }  			
            } else{  				
                if (targetX <= targetY) {  					
                    x1 = startX - 2;  					
                    y1 = targetX + 1;  					
                    x2 = startX - 1;  					
                    y2 = targetX + 2;  				
                } else {  					
                    x1 = startX - 2;  					
                    y1 = targetX - 1;  					
                    x2 = startX - 1;  					
                    y2 = targetX - 2;  				
                }  			
            }  			 			
            // calculate the minimum  			
            min = minimum(countS(x1, y1, targetX, targetY), countS(x2, y2, targetX, targetY)) ; 			
            chessboard[abs(startX - targetX)][abs(targetX- targetY)] = min + 1;  							 			
            // exchanging the coordinates x with y  			
            chessboard[abs(targetX - targetY)][abs(startX - targetX)] = chessboard[abs(startX - targetX)][abs(targetX - targetY)];  			
            // return the result 			
            return chessboard[abs(startX - targetX)][abs(targetX - targetY)];  		
        }  	
    }  
}    

int main(){  	
    int totalSquare, minMove;
    int T;  	
    totalSquare = 100;  	 	
    scanf(" %d", &T); 	 	
    for (int i = 0; i < T; i++){  
        char cx, cx1;
        int y1, y2;
        scanf(" %c%d %c%d", &cx, &y1, &cx1, &y2);
        int x1 = cx - 64, x2 = cx1 - 64; 	 		
        if ((x1 == 1 && y1 == 1 && x2 == 2 && y2 == 2) || (x1 == 2 && y1 == 2 && x2 == 1 && y2 == 1)){
          	minMove = 4;  		
        }else if ((x1 == 1 && y1 == totalSquare && x2 == 2 && y2 == totalSquare - 1) || (x1 == 2 && y1 == totalSquare - 1 && x2 == 1 && y2 == totalSquare)){				
            minMove = 4;
        }else if ((x1 == totalSquare && y1 == 1 && x2 == totalSquare - 1 && y2 == 2) ||  (x1 == totalSquare - 1 && y1 == 2 && x2 == totalSquare && y2 == 1)){
  			minMove = 4;  		
        }else if ((x1 == totalSquare && y1 == totalSquare && x2 == totalSquare - 1 && y2 == totalSquare - 1) || (x1 == totalSquare - 1 && y1 == totalSquare - 1 && x2 == totalSquare && y2 == totalSquare)){ 					
            minMove = 4;  		
        }else {  			
            chessboard[1][0] = 3;  			
            chessboard[0][1] = 3;  			
            chessboard[1][1] = 2;  			
            chessboard[2][0] = 2;  			
            chessboard[0][2] = 2;  			
            chessboard[2][1] = 1;  			
            chessboard[1][2] = 1;  			 				
            minMove = countS(x1, y1, x2, y2);  		
        }  		 		
        printf("Case #%d: %d\n",i+1, minMove);  	
    }
} 