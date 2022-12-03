#include <stdio.h>

int main() {
	int test;
	int counter = 0;
	scanf("%d", &test);
	long long int num[test];
	for(int i = 0; i < test; i++) {
		scanf("%lld", &num[i]);
	}
	for(int k = 0; k < test; k++) {
		for(int j = k + 1; j < test; j++) {
			if(num[k] == num[j]) {
				counter++;
			}
		}	
	}
	int result = test - counter;
	printf("%lld\n", result);
	
	return 0;
}