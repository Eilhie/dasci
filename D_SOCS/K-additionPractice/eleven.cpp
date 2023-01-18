#include<stdio.h>
#include<string.h>

void eleven(char *n){
	// lihat nilai pertama berapa
	int x = n[0]-'0';
	x%=11;
	// lihat sisa berapa
	for(unsigned long long int i=1;i<strlen(n);i++){
		// di looping 
		x*=10;
		x+=(n[i]-'0');
		x%=11;
	}
//	printf("Nilai: %d\n",x);
//	printf("Sisa: %d\n",y);
	x==0?puts("Yeah"):puts("Nah");
}


int main(){
	long long int test;
	scanf("%d",&test);
	getchar();
	char n[100000000];
	for(long long int t=0;t<test;t++){
		scanf("%[^\n]",n);
		getchar();
		printf("Case #%d: ",t+1);
		eleven(n);
		
	}
	
}
