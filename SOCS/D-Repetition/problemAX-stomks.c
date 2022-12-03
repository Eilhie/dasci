#include <stdio.h>

int main(){

    long int N;
    scanf("%ld", &N);

    long long int arr[N];

    for(int i = 0; i < N; i++){
        scanf("%lld", &arr[i]);
    }

    long long int result = 0;

    for(int i = 0; i < N; i++){
        if(arr[i] >= 0){
            result += arr[i];
        }
    }

    printf("%lld\n", result);

    return 0;
}