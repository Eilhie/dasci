#include <stdio.h>
#include <string.h>

int main(){
    int T, flag;
    char S[100];
    scanf("%d", &T);
    for(int j=0; j<T; j++){
        int count=0;
        scanf("%s", S);
        for(int i=0; i<strlen(S); i++){
            if(S[i]=='.'){
                count++;
            }
        }
        for(int i=0; i<strlen(S); i++){
            if(S[0]=='.'||S[strlen(S)-1]=='.'){
                flag=0;
                break;
            }else if(S[i]=='.' && S[i+1]=='.'){
                flag=0;
                break;
            }else if(count != 5){
                flag=0;
                break;
            }else{
                flag=1;
            }
        }
        if(flag==1){
            printf("Case #%d: YES\n", j+1);
        }else{
            printf("Case #%d: NO\n", j+1);
        }
    }
}