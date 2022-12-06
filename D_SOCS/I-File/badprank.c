#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file;
    file = fopen("testdata.in", "r");
    int T;
    fscanf(file, "%d\n", &T);
    char key[9] = "OI`EASGTB";
    for(int i=0; i<T; i++){
        int N;
        fscanf(file, "%d\n", &N);
        char string[1000];
        fscanf(file, "%[^\n]\n", string);
        int len = strlen(string);
        for(int j=0; j<len; j++){
            for(int k=0; k<9; k++){
                if(string[j]-'0'==k){
                    string[j]=key[k];
                }
            }
        }
        for(int j=0; j<len; j++){
            if(string[j]!=' '){
                if(string[j]-N<'A'){
                    string[j]='Z'-(N-(string[j]-'A'))+1;
                }else{
                    string[j]-=N;
                }
            }
        }
        printf("Case #%d: %s\n", i+1, string);
    }
}