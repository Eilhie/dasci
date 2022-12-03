#include <stdio.h>

int min(int a, int b){
    int countr = 0, countl = 0, start=1;
    if(a%2==0){
        a=a;
    }else{
        a=a-1;
    }
    while(a>b){
        a-=2;
        countr++;
    }
    while(start<b){
        start+=2;
        countl++;
    }
    if(countl<countr){
        return countl;
    }else{
        return countr;
    }
    
}

int main(){
    int t;
    long long int r, noPages; 
    scanf("%d", &t);
    for(int i=0; i<t; i++){       
        scanf(" %lld %lld", &noPages, &r);
        int result = min(noPages, r);
        printf("Case #%d: %d\n", i+1, result);
    }
}