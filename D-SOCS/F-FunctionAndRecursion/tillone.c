#include <stdio.h>

long long int tillOne(int a){
    if(a == 1){
        return 1;
    } else if(a % 2 != 0){
        return tillOne(a - 1) + tillOne(a + 1);
    } else {
        return tillOne(a / 2);
    }
    
}

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        long long int nums;
        scanf("%d", &nums);
        printf("Case #%d: %lld\n", i + 1, tillOne(nums));
    }

    return 0;
}