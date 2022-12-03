#include <stdio.h>

int main(){

    int test;
    scanf("%d", &test);
    for(int i = 0; i < test; i++){
        int len;
        scanf("%d", &len);
        int arr[len];
        for(int j = 0; j < len; j++){
            scanf("%d", &arr[j]);
        }
        int result = 0;
        for(int j = 0; j < len; j++){
            int count = 0;
            for(int k = 0; k < len; k++){
                for(int l = 0; l < len; l++){
                    if(j != k && j != l && k != l){
                        if(arr[j] == arr[k] + arr[l]){
                            count++;
                        }
                    }
                }
            }
            if(count > 0){
                result += 1;
            } 
        }
       printf("Case #%d: %d\n", i + 1, result);

    }

    return 0;
}

