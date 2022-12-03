#include<stdio.h>

int main()
{
    long int arr[1000], size, sum = 0;
    
    scanf("%ld",&size);
    
    for(int i = 0; i < size; i++){
        scanf("%ld",&arr[i]);
    }
          

    for(int i = 0; i < size; i++){
        sum = sum + arr[i]; 
    }
          
    printf("%ld\n",sum);
    
    return 0;
}