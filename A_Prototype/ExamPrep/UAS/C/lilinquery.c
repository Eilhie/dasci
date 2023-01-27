#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target){
    if(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == target) {
            int leftmost = binarySearch(arr, left, mid - 1, target);
            if(leftmost == -2) return mid;
            else return leftmost;
        }
        if (arr[mid] > target) return binarySearch(arr, left, mid - 1, target);
        if (arr[mid] < target) return binarySearch(arr, mid + 1, right, target);
    }
    
    return -2;
}

int main(){
    int len, cng;
    scanf("%d %d", &len, &cng); getchar();

    int arr[len], changes;
    for(int i = 0; i < len; i++) scanf(" %d", &arr[i]);
    
    for(int i = 0; i < cng; i++){
        scanf(" %d", &changes);
        printf("%d\n", binarySearch(arr, 0, len-1, changes)  + 1);
    } 
    
    

    return 0;
}
