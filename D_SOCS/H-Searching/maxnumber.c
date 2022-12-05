#include <stdio.h>

int main(){

    int len, length;
    scanf("%d %d", &len, &length);
    int arr[len];
    int rev[length];
    for(int i = 0; i < len; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < length; i++)
        scanf("%d", &rev[i]);

    for(int i = 0; i < length; i++){
        for(int j = 0; j < len; j++){
            if(rev[i] == arr[j]){
                for(int k = j; k < len - 1; k++){
                    arr[k] = arr[k + 1];
                }
                j--; 
                len--;
            }
        }
    }
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(arr[i] == arr[j]){
                for(int k = j; k < len - 1; k++){
                    arr[k] = arr[k + 1];
                }
                j--; 
                len--;
            }
        }
    }
    
    int max = -1;
    for(int i = 0; i < len; i++){
        if(max < arr[i]) max = arr[i];
        else if (max == arr[i]) max = -1;
    }
    printf("Maximum number is %d\n", max);
    return 0;
}