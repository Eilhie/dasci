#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

int partition(char array[], int low, int high){
    int i = low;

    for(int j=low; j<high; j++){
        if(array[j]<=array[high]){
            swap(&array[i], &array[j]);
            i++;
        }
    }

    swap(&array[i], &array[high]);
    
    return i;
}

void quicksort_recursion(char array[], int low, int high){
    if (low<high){
        int pivotIndex = partition(array, low, high);
        quicksort_recursion(array, low, pivotIndex-1);
        quicksort_recursion(array, pivotIndex + 1, high);
    }
}

void quicksort(char array[], int length){

    quicksort_recursion(array, 0, length-1);
}

void swap_str(char **x, char **y){
    char *temp = *x;
    *x = *y;
    *y = temp;
}


int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        char *string = (char *) malloc (sizeof(char) * (int) pow(10, 6)); 
        scanf("%s", string);
        int result = 0;
        quicksort(string, strlen(string));
        printf("%s\n", string);
        for(int k = 0; k < strlen(string) ; k++){
            int count = 1;
            
            for(int j = k + 1 ; j < strlen(string) - 1; j++){    
                if(string[k] == string[j]){
                    count++;
                }
            }  

            if(count > 0) result++;
        } 
        if(result % 2 == 0)
            printf("Case #%d: Yay\n", i + 1);
        else 
            printf("Case #%d: Ewwww\n", i + 1);

        printf("%s %d\n", string, result);
    }

    return 0;
}