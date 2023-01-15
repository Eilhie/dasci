#include <stdio.h>
#include <string.h>

void revstr(char *str1){
    int i, len, temp;
    len=strlen(str1);
    for(i=0;i<len/2;i++){
        temp = str1[i];
        str1[i]= str1[len-i-1];
        str1[len-i-1] = temp;
    }
}

int main(){
    char kontol[] = "anjay gurinjay gurame makjang";
    char list[100][100];
    char *token = strtok(kontol, " ");
    int l=0;
    while(token!=NULL){
        if(l%2==1){
            revstr(token);
        }
        strcpy(list[l], token);
        token = strtok(NULL, " ");
        l++;
    }
    for(int i=0; i<l; i++){
        if(i==l-1){
            printf("%s\n", list[i]);
        }else{
            printf("%s ", list[i]);
        }
    }
}