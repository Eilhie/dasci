#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        int JUMP;
        char string[100];
        scanf("%d", &JUMP); getchar();
        scanf("%[^\n]", string); getchar();
        int j = 0;
        while(string[j] != '\0'){
            if(string[j + JUMP-1] == 'b' || string[j + JUMP-1] == 'u' || string[j + JUMP-1] == 'd' || string[j + JUMP-1] == 'i'){
                    // 
            }else{
                string[j + JUMP-1] = toupper(string[j + JUMP-1]);
            }

            j += JUMP;
        }
        puts(string);
    }

    return 0;
}