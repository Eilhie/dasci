#include<stdio.h>

long long int binsearch(long long int x){
	long long int mid, ans;
	long long int left = 1, right = 1500000;
	while(left <= right){
		mid = (left + right)/2;
		if(mid*(mid+1)*(2*mid+1)/6 == x){
			ans = mid;
			break;
		}
		else if(mid*(mid+1)*(2*mid+1)/6 < x){
			left = mid + 1;
		}
		else{
			right = mid - 1;
			ans = mid;
		}
	} 
	return ans;
}

int main(){
		int tc;
		long long int m;
		scanf("%d", &tc); getchar();
		for(int i = 1; i <= tc; i++){
			scanf("%lld", &m); getchar();
			printf("Case #%d: %lld\n", i, binsearch(m));
		}
	return 0;
}