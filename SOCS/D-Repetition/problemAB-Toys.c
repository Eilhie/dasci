// #include <stdio.h>

// int main(){

//     int testCases;

//     scanf("%d", &testCases);

//     long int N[testCases], A[testCases], B[testCases], C[testCases], D[testCases];

//     for(int i = 0; i < testCases; i++){
//         scanf("%ld %ld %ld %ld %ld", N[i], A[i], B[i], C[i], D[i]);
//     }
//     long int total[testCases];
//     for(int i = 0; i < testCases; i++){
//         total[i] = 0;
//         while(N[i]>0){
// 			if(N[i] % A[i] == 0){
// 				total[i] += 1;	
// 			}
// 			else if(N[i] % B[i] == 0){
// 				total[i] += 1;
// 			}
// 			else if(N[i] % C[i] == 0){
// 				total[i] += 1;
// 			}
// 			else if(N[i] % D[i] == 0){
// 				total[i] += 1; 
// 			}
// 			N[i]--;
// 		}
// 	    printf("Case #%d: %ld\n",i + 1, total[i]);
//     }

//     return 0;
// }


#include <stdio.h>

int main (){
	int t;
	unsigned int a[10000],b[10000],c[10000],d[10000],e[10000];	
	scanf("%d", &t); 
	
	int total[100];
	
	for(int i = 0; i<t ;i++){
		scanf("%u %u %u %u %u", &a[i],&b[i],&c[i],&d[i],&e[i]);
	}
	
	for(int i = 0; i<t; i++){
		for(int j = 0; j < a[i]; j++){
			if(a[i]%b[i]==0){
				total[i] +=1;	
			}
			else if(a[i]%c[i]==0){
				total[i] +=1;
			}
			else if(a[i]%d[i]==0){
				total[i] +=1;
			}
			else if(a[i]%e[i]==0){
				total[i] +=1; 
			}
		}
		
			
		
	printf("Case #%d: %u\n",i+1,total[i]);
	
	}
	
	
	
	return 0;
}


// #include <stdio.h>

// int main(){
//   	int t;
  
//   	scanf("%d",&t);
//   	int a[t],b[t],c[t],d[t],e[t];
//   	int total[t];

//   	for(int i = 0 ; i < t ; i++){
//   	  scanf("%d %d %d %d %d",&a[i],&b[i],&c[i],&d[i],&e[i]);
// 	// }
// 	// for(int i = 0; i < t;i++){
// 		total[i] = 0;
// 		for(int j = 0; j < a[i]; j++){
// 			if(a[i]%b[i]==0){
// 				total[i] +=1;	
// 			}
// 			else if(a[i]%c[i]==0){
// 				total[i] +=1;
// 			}
// 			else if(a[i]%d[i]==0){
// 				total[i] +=1;
// 			}
// 			else if(a[i]%e[i]==0){
// 				total[i] +=1; 
// 			}
// 		}
// 		printf("Case #%d: %d\n", i + 1, total[i]);
// 	}

//   return 0;
// }