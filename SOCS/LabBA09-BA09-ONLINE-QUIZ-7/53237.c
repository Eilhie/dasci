#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    
    char string[10000];
    scanf("%[^\n]", string);
    for(int j = 0; j < strlen(string); j++){
        string[j] = toupper(string[j]);
        switch (string[j]){
        case 'I':
            string[j] = '1';
            break;
        case 'R':
            string[j] = '2';
            break;
        case 'E':
            string[j] = '3';
            break;
        case 'A':
            string[j] = '4';
            break;
        case 'S':
            string[j] = '5';
            break;
        case 'G':
            string[j] = '6';
            break;
        case 'T':
            string[j] = '7';
            break;
        case 'B':
            string[j] = '8';
            break;
        case 'P':
            string[j] = '9';
            break;
        case 'O':
            string[j] = '0';
            break;

        default:
            break;
        }    
    }
    printf("%s\n", string);
    
    return 0;
}