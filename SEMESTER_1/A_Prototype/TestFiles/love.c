#include <stdio.h>

int main(){

    int len;
    scanf("%d", &len);

    int arr[len];

    for(int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    long int change;
    scanf("%ld", &change);

    for(int i = 0; i < change; i++){
        long int a, b;
        scanf("%ld %ld", &a, &b);
        arr[a-1] = b;
        printf("Case #%d:", i+1);
        for(int j = 0; j < len; j++){
            printf(" %d", arr[j]);
        }
        printf("\n");
    }

    return 0;
}
