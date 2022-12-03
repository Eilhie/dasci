#include <stdio.h>

long long int epicgames(long long int nums, long long int *player){
    *player = *player + 1;

    if(nums == 1) return 1;
    else if(nums % 2 == 0) return epicgames(nums / 2, player);
    else return epicgames(nums * 3 + 1, player);
}

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        long long int num;
        scanf(" %lld", &num);
        long long int player = 0;
        epicgames(num, &player);
        printf("Case #%d:", i + 1);
        if(player %2 == 0) printf(" Jojo\n");
        else printf(" Lili\n");
        
    }

    return 0;
}