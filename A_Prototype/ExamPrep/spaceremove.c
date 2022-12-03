#include <stdio.h>
#include <string.h>

int main(){

    char string[] = {"taco cat"};
    int len = strlen(string);
    printf("%s\n", string);
    for(int i = 0; i < len; i++){
        if(string[i] == ' '){
            
            for(int j = i; j < len; j++){
                string[j] = string[j + 1];
            }
            len = len--;
        }
    }
    printf("%s\n", string);

    return 0;
}