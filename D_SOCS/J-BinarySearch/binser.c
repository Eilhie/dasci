#include <stdio.h>
 
unsigned long long int sum(unsigned long long int m) {
        return (m * (m + 1) * ((2 * m) + 1)) / 6; 
} 
unsigned long long int find(unsigned long long int left,unsigned long long int right,unsigned long long int m) {
        unsigned long long int mid=(left+right)/2;     
        while(mid<right) {         
            if(sum(mid)>m) {
                right=mid;             
                mid=(left+mid-1)/2;         
            } else if(sum(mid)<m){             
                left=mid;             
                mid=(mid+1+right)/2;         
            } else 
                return mid;     
        }     
        if(sum(mid)>=m)         
            return mid;     
        else         
            return mid+1; 
} 

int main() {     
    int T;         
    scanf("%d",&T);     
    int i;     
    for(i=1;i<=T;i++){         
        unsigned long long int M;                
        scanf("%llu",&M);         
        printf("Case #%d: %llu\n",i,find(1,M,M)); 
        //printf("%llu\n", sum(find(1, M, M)));   
    }     
    return 0; 
}