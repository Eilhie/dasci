#include <stdio.h>
#include <string.h>

void stringsort(char str[], int length){
    char temp;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - 1; j++){
            if(str[j] > str[j + 1]){
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main(){
    char string[][4] = {"teri", "neko", "sika", "wara"};

    stringsort(string[1], strlen(string[1]));

    printf("%s\n", string[1]);

    return 0;
}