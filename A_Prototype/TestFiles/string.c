#include <stdio.h>
#include <string.h>

int main(){

    char string[100] = "krisna";
    char str[50] = "gay";

    strcat(string, str);
    printf("%s\n", string);


    char temp[50];
    strcpy(temp, string);
    printf("%s\n", temp);

    return 0;
}