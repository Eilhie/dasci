#include <stdio.h>

int main(){

    int size;
    scanf("%d", &size);

    int index[size], arr[size];

    for(int i = 0; i < size; i++){
        scanf("%d", &index[i]);
    }
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    int temp, arrtemp;
     for (int i = 0; i < size; i++) {     
        for (int j = i+1; j < size; j++) {     
           if(index[i] > index[j]) {    
               temp = index[i];    
               arrtemp = arr[i];

               index[i] = index[j]; 
               arr[i] = arr[j];
               index[j] = temp; 
               arr[j] = arrtemp;   
           }     
        }     
    }    
    
    for(int i = 0; i < size; i++){
        if(i == size-1){
            printf("%d\n", arr[i]);
        } else{
            printf("%d ", arr[i]);
        }
        
    }

    return 0;
}