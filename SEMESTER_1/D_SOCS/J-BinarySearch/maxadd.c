#include <stdio.h>

long long int max(int N, long long int mid, long long int letf, long long int right, long long int nums[]){
    long long int total = nums[letf];
    long long cek = 0;
    while(right <= N){
        if(total <= mid){
            if(right-letf+1 > cek)
   		        cek= right-letf+1;
            right++;
            if(right <= N)
   		        total += nums[right];
        }
		else{
            total-=nums[letf];
            letf++;
        }
    }
    return cek;
}

int main() {
    int tc,n; 
 	scanf("%d", &tc); 
    for(int i = 0; i < tc; i++){
        scanf("%d", &n);
        long long int m;
        scanf("%lld", &m); 
        long long int number[n+5];
        for(int j = 1; j <= n; j++){
            scanf("%lld", &number[j]); 
        }
        long long int ans;
        ans = max(n, m, 1, 1, number);
        if(!ans){
            printf("Case #%d: %d\n", i+1, -1);
        }
        else{
            printf("Case #%d: %lld\n", i+1, ans);
        }
    }
    return 0;
}