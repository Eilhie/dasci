#include <stdio.h>


int main (){
	char a [101];
	char b [101];
	char c [101];
	scanf("%c %c %c",a,b,c);
	if(a<b&&a<c){
		printf("1 ");getchar();
	if(b<c){
		printf("2 3\n");
	}else{
		printf("3 2\n");
	}
	}
	if(b<a&&b<c){
		printf("2 ");getchar();
	if(a<c){
		printf("1 3\n");
	}else{
		printf("3 1\n");
	}
	}
	if(c<a&&c<b){
		printf("3 ");getchar();
	if(a<b){
		printf("1 2\n");
	}else{
		printf("2 1\n");
	}
	}
	
	
	
	
	return 0;
}