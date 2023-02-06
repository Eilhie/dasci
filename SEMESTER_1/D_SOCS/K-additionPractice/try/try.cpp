#include <stdio.h>

struct employee
{
   int a;
};



void swap(employee *a, employee *b){
    employee
    t = *a;
    *a = *b;
    *b = t; 
}

int partition(employee arr[], int low, int high){
    employee
    pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high-1; j++){
        if(arr[j].a < pivot.a){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[high], &arr[i + 1]);
    return i + 1;
}

void quickSort(employee arr[], int low, int high){
    if(low <= high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
   int a;
   scanf("%d", &a); getchar();
   employee
 arr[a];
   for(int j = 0; j < a; j++){
      scanf("%d", &arr[j].a); getchar();
   }
   

   quickSort(arr, 0, a - 1);

    for(int i = 0; i < a; i++){
        printf("%d ", arr[i].a);
    }
    puts("");

    return 0;
}