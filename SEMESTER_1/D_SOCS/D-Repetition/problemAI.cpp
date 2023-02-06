#include <stdio.h>
int main() {
	long long int t, n, left, right, split, pos, arr[100100];
	
	scanf("%lld", &t);
	for (int i = 1; i <= t; i++) {
		left = 0; right = 0;
		pos = 1;
		scanf("%lld", &n);
		for (int j = 0; j < n; j++) {
			scanf("%lld", &arr[j]);
		(j == 0)?left += arr[j]:right += arr[j];	
		}
		while (pos != n && left != right) {
			left += arr[pos];
			right -= arr[pos];
			pos++;
		}
		printf("Case #%d: ", i);
		(right == left)?printf("Yes\n"):printf("No\n");
	}
	return 0;
}