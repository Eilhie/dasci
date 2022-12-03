#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int len;
    scanf("%d", &len);
    char arr[len][100];
    int nums[len];
    char temp[100];

    for (int i = 0; i < len; i++)
        scanf("%s %d", arr[i], &nums[i]);
    
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (nums[j] > nums[j + 1]){
                swap(&nums[j], &nums[j + 1]);
                strcpy(temp, arr[j]);
                strcpy(arr[j],  arr[j + 1]);
                strcpy(arr[j + 1], temp);
            } 
            else if(nums[j] == nums[j + 1]) {
                if (strcmp(arr[j], arr[j + 1]) > 0){
                    strcpy(temp, arr[j]);
                    strcpy(arr[j],  arr[j + 1]);
                    strcpy(arr[j + 1], temp);
                }
            }
                
        }
    }

    for (int i = 0; i < len; i++)
        printf("%s\n", arr[i]);
 
    return 0;
}