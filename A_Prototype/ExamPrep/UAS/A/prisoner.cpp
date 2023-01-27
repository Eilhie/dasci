#include <stdio.h>
#include <math.h>

int LMBinarySearch(long long int arr[],int left, int right,int target){
    if(left<right){
        int mid = (left+right)/2;
        if(arr[mid]==target){
            int leftmost = LMBinarySearch(arr,left,mid-1,target);
            if(leftmost == -1) return mid;
            else return leftmost;  
        } else if(arr[mid]>target) return LMBinarySearch(arr,left,mid-1,target);
        else if(arr[mid]<target) return LMBinarySearch(arr,mid+1,right,target);
    }
    return -1;
}

int main(){
    int tc; 
    scanf("%d", &tc);
    for(int i = 0; i < tc; i++){
        int len;
        scanf("%d", &len);
        long long int arr[len];
        float target = 0;
        for(int j = 0; j < len; j++){
            scanf("%lld", &arr[j]);
            target += arr[j];
        }
        target /= len;
        if(target - (int)target < 0.5) target = floor(target);
        else target = ceil(target);
        printf("Case #%d: %d\n", i + 1, LMBinser(arr, 0, len - 1, target) + 1);
    }
    return 0;
}