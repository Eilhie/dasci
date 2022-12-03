#include <stdio.h>

using namespace std;

int xSum(int n, int m){

	int res = 0;

	int multiplier = 1;

	int bit_sum;

	while (n || m) {

		bit_sum = (n % 10) + (m % 10);

		bit_sum %= 10;

		res = (bit_sum * multiplier) + res;
		n /= 10;
		m /= 10;

		multiplier *= 10;
	}
	return res;
}
int main()
{
	int testCases;
	scanf("%d", &testCases);
	for(int i = 0; i < testCases; i++){
		int n, m;
		scanf("%d %d", &n, &m);
		printf("Case #%d: %d\n", i + 1, xSum(n, m));
	}
	
	return 0;
}
