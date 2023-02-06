#include<stdio.h>
char chess_board[8][8];
int found;
int limit;

void ffl(int step, char which, int xpos, int ypos){
 if(xpos < 0 || ypos < 0 || xpos > 7 || ypos > 7){
  return;
 }
 
 if(chess_board[ypos][xpos] == which){
  return;
 }
 
 if(step > limit || found){
  return;
 }
 
 if((which == 'B' && chess_board[ypos][xpos] == 'W') || (which == 'W' && chess_board[ypos][xpos] == 'B')){
  found = 1;
  return;
 }
 chess_board[ypos][xpos] = which;
 
 ffl(step+1, which, xpos+2, ypos+1);
 ffl(step+1, which, xpos+2, ypos-1);
 ffl(step+1, which, xpos-2, ypos-1);
 ffl(step+1, which, xpos-2, ypos+1); 
 ffl(step+1, which, xpos+1, ypos+2); 
 ffl(step+1, which, xpos+1, ypos-2); 
 ffl(step+1, which, xpos-1, ypos-2); 
 ffl(step+1, which, xpos-1, ypos+2); 
}

int main(){
 int tc, White_PosX, White_PosY, Black_PosX, Black_PosY;
 char whitec, blackc;
 scanf("%d", &tc); getchar();
 
 for(int i = 0; i<tc; i++){
  for(int j = 0; j<8; j++){
   for(int k = 0; k<8; k++){
    chess_board[j][k] = ' ';
   }
  }
  
  scanf("%d", &limit); getchar();
  scanf("%c%d %c%d", &whitec, &White_PosY, &blackc, &Black_PosY); getchar();
  
  White_PosX = whitec - 'A';
  Black_PosX = blackc - 'A';
  White_PosY = 8 - White_PosY;
  Black_PosY = 8 - Black_PosY;
  
  found = 0;
  ffl(0, 'W', White_PosX, White_PosY);
  ffl(0, 'B', Black_PosX, Black_PosY);
  
  if(found){
   printf("Case #%d: YES\n", i+1);
  } else {
   printf("Case #%d: NO\n", i+1);
  
  }
 }
}