#include <stdio.h>

int main(){

    int testCases;

    scanf("%d", &testCases);
    
    long long int num[testCases], pos[testCases];

    for(int i = 0; i < testCases; i++){
        scanf("%lld %lld", &num[i], &pos[i]);
    }

    for(int i = 0; i < testCases; i++){
        if((num[i] >> pos[i]) & 1) {
			printf("1\n");
		} else {
			printf("0\n");
		}
    }

    return 0;
}