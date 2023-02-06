// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// int main() {
//     int M;
//     scanf("%d", &M);

//     long long a[M], b[M], c[M], N[M];
//     for (int i = 0; i < M; i++) scanf("%lld", &a[i]);
//     for (int i = 0; i < M; i++) scanf("%lld", &b[i]);
//     for (int i = 0; i < M; i++) scanf("%lld", &c[i]);
//     for (int i = 0; i < M; i++) scanf("%lld", &N[i]);

//     for (int i = 0; i < M; i++) {
//         int run = 1;
//         int x = 0;
//         while(run){
//             if((a[i]*(int)pow(x,3) + b[i]*(int)pow(x,2) + c[i]*x) > N[i]) {
//                 printf("%d\n", x-1); run = 0;
//             } 
//             x++;
//         }
        
//     }
//     return 0;
// }

#include <stdio.h>
#include <math.h>

long long int binsearch(long long int a, long long int b, long long int c, long long int n){
	long long int mid, ans;
	long long int left = 1, right = 10000;
	while(left <= right){
		mid = (left + right)/2;
		if(a * mid * mid * mid + b * mid * mid + c * mid == n){
			ans = mid;
			break;
		}
		else if(a * mid * mid * mid + b * mid * mid + c * mid < n){
			left = mid + 1;
            ans = mid;
		}
		else{
			right = mid - 1;
		}
	} 
	return ans;
    // long long int X = (-b + sqrt(b*b - 4*a*(c-n)))/(2*a);
    // return X;
}

int main() {
    int M;
    scanf("%d", &M);

    long long a[M], b[M], c[M], N[M];
    for (int i = 0; i < M; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < M; i++) scanf("%lld", &b[i]);
    for (int i = 0; i < M; i++) scanf("%lld", &c[i]);
    for (int i = 0; i < M; i++) scanf("%lld", &N[i]);

    for (int i = 0; i < M; i++) {
        printf("%lld\n", binsearch(a[i], b[i], c[i], N[i]));
    }
    return 0;
}

