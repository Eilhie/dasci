#include <stdio.h>

int main(){
  int count, N, K, left, right, total;
    char string[10000];
    scanf("%d", &count);
    for(int i = 1; i <= count; i++){
        scanf("%d %d", &N, &K);
        scanf("%s", &string);
        getchar();
        total = 0;

        for(int j = 0; j < N;j++){
            if(string[j] =='1'){
                left = j+1;
                break;
            }
        }
        for(int k = N-1;k >=0; k--){
            if(string[k] == '1'){
                right = k;
                break;
            }
        }
        for(int l = 0; l < N; l++){
            if(string[l] == '1'){
                total+=1;
            }
        }
        if(total == 0 || total == 1){
            if(N <= K){
                printf("Case #%d: Alive\n", i);
            }
            else{
                printf("Case #%d: Dead\n", i);
            }
        }
        else{
            if(left <= K  && N - right <= K ){
                printf("Case #%d: Alive\n", i);
            }
            else{
                printf("Case #%d: Dead\n", i);
            }
        }
    }
    
  return 0;
}
