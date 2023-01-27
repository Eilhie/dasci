#include <stdio.h>

// void fraktal_A(int x) { 
//   int i; 
//   if (x <= 0) return; 
//   else { 
//     fraktal_A(x - 1); 
//     for (i = 1; i <= x; i++) printf("*"); 
//     printf("\n"); 
//     fraktal_A(x - 1); 
//   } 
// }

int main(){
    int x;
    scanf("%d", &x);
    unsigned long long int fractal[100000] = {0, 1 ,4 , 11};
    if(x < 4) printf("%llu\n", fractal[x]);
    else{
        for(int i = 4; i <= x; i++){
            fractal[i] = ((fractal[i - 1] + fractal[i - 1] + i) % 1000000000);
        }
        printf("%llu\n", fractal[x]);
    }
    
    return 0;
}