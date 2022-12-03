// #include <stdio.h>

// int main(){

//     int numCases;
    
//     scanf("%d", &numCases);
//     long long int list[numCases][numCases];

//     for(int i = 0; i < numCases; i++){
//         scanf("%lld %lld", &list[i][0], &list[i][1]);
//     }
//     for(int i = 0; i < numCases; i++){
//         if((list[i][0]*list[i][1]) % 2 == 0){
//             printf("Case #%d: Party time!\n", i+1);
//         }else {
//             printf("Case #%d: Need more frogs\n", i+1);
//         }
//     }

//     return 0;
// }

#include <stdio.h>

int main(){
    long long int T;
    scanf("%lld", &T);
    long long int list[T][T];
    for(int i = 0; i<T; i++){
        scanf(" %lld %lld", &list[i][0], &list[i][1]);
    }
    for(int i = 0; i<T; i++){
        if((list[i][0]*list[i][1]) % 2 == 0){
            printf("Case #%d: Party time!\n", i +1);
        }else{
            printf("Case #%d: Need more frogs\n", i+1);
        }
    }
    return 0;
}