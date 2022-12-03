// program for nth Fibonacci word
#include <stdio.h>
#include <string.h>

const char* fibWord(int n, char a, char b){
	char *temp;
	for(int i = 2; i <= n; i++){
		*temp = a;
		strcat(a,b);
		b = *temp;
	}
	return a;
}

int main(){
	int testCases; 
	scanf("%d", &testCases);

    for(int i = 0; i < testCases; i++){
        int n; 
        char a, b;
        scanf("%d %c %c", &n, &a, &b);
        printf("%s\n",fibWord(n, a, b));
    }
	
	return 0;
}
