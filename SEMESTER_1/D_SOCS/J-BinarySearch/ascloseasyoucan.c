#include <stdio.h>

long long int binarySearch(long long int arr[], long long int x, long long int low, long long int high){
    int mid = 0;
	while(low <= high){
		mid = (low + high)/2;
		if(arr[mid] <= x && arr[mid+1] > x){
			break;
		}
		else if(x < arr[mid]){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return mid;
}

int main(){

    long long int n,cases,search,a[100001] = {};
	scanf("%lld", &n); getchar();
	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]); getchar();
		if(i == 0){
			a[i] = a[i];
		}
		else{
			a[i] += a[i-1];
		}
	}
	scanf("%lld", &cases); 
    getchar();
	for(int i = 0; i < cases; i++){
		scanf("%lld", &search); getchar();
		if(a[0] > search){
			printf("Case #%d: %d\n", i+1, -1);
		}
		else if(a[n-1] <= search){
			printf("Case #%d: %lld\n", i+1, n);
		}
		else{
			printf("Case #%d: %lld\n", i+1, binarySearch(a,search,0,n+1)+1);
		}
	}
	return 0;

    return 0;
}