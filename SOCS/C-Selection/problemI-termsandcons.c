// #include <stdio.h>

// int main(){

//     int numCases;
    
//     scanf("%d", &numCases);
//     long int list[numCases][numCases+1];

//     for(int i = 0; i < numCases; i++){
//         scanf("%ld %ld %ld", &list[i][0], &list[i][1], &list[i][2]);
//     }
//     for(int i = 0; i < numCases; i++){
//         long int discounted = list[i][0] * list[i][1]/100;
//         if(list[i][2]<= discounted){
//             printf("Case #%d: %d\n", i+1, list[i][2]);
//         }else{
//             printf("Case #%d: %d\n", i+1, discounted);
//         }
//     }

//     return 0;
// }

// #include <stdio.h>

// int main(){

//     int numCases;
    
//     scanf("%d", &numCases);
//     long int a,b,c;

//     for(int i = 0; i < numCases; i++){
//         scanf("%ld %ld %ld", &a, &b, &c);
    
//         long int discounted = a * b/100;
//         if(c<= discounted){
//             printf("Case #%d: %d\n", i+1, c);
//         }else{
//             printf("Case #%d: %d\n", i+1, discounted);
//         }
//     }

//     return 0;
// }

#include <stdio.h>


int main(){
	int TestCases;
	long int a,b,c;
	scanf("%d", &TestCases);
	for(int i=0;i<TestCases;i++){
		scanf("%ld %ld %ld", &a, &b, &c);
		long int discounted = a*b/100;
		if(c<=discounted){
			printf("Case #%d: %d\n",i+1,c);
		}else{
			printf("Case #%d: %d\n",i+1,discounted);
		}
		
	}
	return 0;
}
