#include <stdio.h>

void merge(int arr[], int left, int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = arr[i + mid + 1];
    }
    int k = left;
    int i = 0, j = 0;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right){
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
 
        merge(arr, left, mid,right);
    }
}

int main(){

    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    mergesort(arr, 0, len - 1);

    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    puts("");

    return 0;
}