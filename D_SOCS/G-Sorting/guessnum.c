#include <stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int list[], int low, int high){
    int i=low;
    for(int j=low; j<high; j++){
        if(list[j]<=list[high]){
            swap(&list[j], &list[i]);
            i++;
        }
    }
    swap(&list[i], &list[high]);
    return i;
}

void quicksort_recursion(int *list, int low, int high){
    if(low<high){
        int pivotIndex = partition(list, low, high);
        quicksort_recursion(list, low, pivotIndex-1);
        quicksort_recursion(list, pivotIndex+1, high);
    }
}

void quicksort(int list[], int size){
    
    quicksort_recursion(list, 0, size-1);
}

int main(){
    int T;
    scanf("%d", &T);
    for(int m = 0; m < T; m++){
        int list[25], result[5], used[25]={0}, sum=0;
        for(int j=0; j<25; j++){
            scanf(" %d", &list[j]);
            sum+=list[j];
        }
        quicksort(list, 25);
        result[0] = list[0]/2;
        used[0] = 1;
        int j=0;
        for(int x=1; x<5; x++){
            while(j<25 && used[j]){
                j++;
            }
            result[x]=list[j]-result[0];
            
            for(int i=0;i<x;i++){
                int count=0;
                for(int k=0;(k<25 && count<2);k++){
                    if(!used[k] && list[k]==(result[i]+result[x])){
                        used[k]=1;
                        count++;
                    }
                }
            }
            
            for(int i=0;i<25;i++){
                if(!used[i] && list[i]==(result[x]*2)){
                    used[i]=1;
                    break;
                }
            }
        }
        
        printf("Case #%d:", m+1);
        for(int i=0;i<5;i++){
            printf(" %d", result[i]);
        }
        printf("\n");
    }
}