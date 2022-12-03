#include <stdio.h>
#include <string.h>

void revstr(char *str1){
    int i, len, temp;
    len=strlen(str1);
    for(i=1;i<len/2;i++){
        temp = str1[i];
        str1[i]= str1[len-i-1];
        str1[len-i-1] = temp;
    }
}

int main(){
    
    int testCases;
    scanf("%d", &testCases);
    getchar();
    for(int i = 1; i <= testCases; i++){
        char string[101];
        char result[11][101];
        scanf("%[^\n]", string);

        char *token = strtok(string, " ");
        int l = 0;
        while(token != NULL){
            revstr(token);
            strcpy(result[l], token);
            token = strtok(NULL, " ");
            l++;
        }
        for(int j = 0; j < l; j++){
            printf("%s ", result[j]);
        }
        puts("");
    }
    return 0;
}