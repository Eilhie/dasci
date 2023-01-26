#include <stdio.h>

int main() {
	int test;
	scanf("%d",&test);
	for(int t=0;t<test;t++){
    	long long int n;
    	scanf("%lld", &n);
    	long long int sum = 0;
    	for (long long int i = 1; i < n; i++) {
        	sum += (n - i) * i;
    	}
    	sum += n;
    	printf("Case #%lld: %lld\n",t+1, sum);
	}
    return 0;
}

