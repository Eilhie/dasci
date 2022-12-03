#include <stdio.h>

int main(){
   int n,sum=0,pos;
  scanf("%d",&n);
   int d[n];
  
  for(int i = 0 ; i < n; i++){
    scanf("%d",&d[i]);
      sum += d[i];
  if(sum == 30){
  sum = 10;
  }
  else if(sum == 12){
    sum=28;
  }
    else if(sum == 35){
    sum=7;
  }
    else if(sum >= 40){
    sum-=40;
    }
}
  printf("%d\n",sum);
  return 0;
}