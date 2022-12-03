#include <stdio.h>

void countBranches(int currentPos, int currentSum, int data[], int size) {         
    // currentPos=0, currentSum=0, size = 5;
    int d = data[currentPos];     
    if(currentPos*2+1 < size){//branch kiri          
        countBranches(currentPos*2+1, currentSum + d, data, size);
        if(currentPos*2+2 < size){//branch kanan                         
            countBranches(currentPos*2+2, currentSum + d, data, size);
        } 
    }else{
        printf("%d\n", currentSum+d);
    }
} 

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        int n, list[100];
        scanf(" %d", &n);
        for(int j=0; j<n; j++){
            scanf(" %d", &list[j]);
        }
        printf("Case #%d:\n", i+1);
        countBranches(0, 0, list, n);
    }
}