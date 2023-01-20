#include<stdio.h>
//+2,+4,+6
//1,3,7 = 
//1,3,5 = (2*n)-1;

void snowflake(int n){
    int tergede = (n-1)*2+1;
	int height = 1;
	int tambah = 2;
	for(int i=1;i<n;i++){
		height += tambah;
		tambah+=2;
	}
	
    int count = 1;
    for(int i=1; i<=height; i++){
        for(int j=1; j<=tergede; j++){
            if(i%2!=0){
                if(j==n){
                    printf("*");
                }else{
                    printf(" ");
                }
            }else{
                if((j>=n-count && j<=tergede-count) || (j==n-count-1 || j==tergede-count+1)){
                    printf("*");
                }else{
                    printf(" ");
                }
            }
        }
        if(i<tergede-1){
                count--;
            }else{
                count++;
            }
        printf("\n");
    }
}


int main(){
	int n;
	scanf("%d",&n);
    snowflake(n);
    return 0;	
}

