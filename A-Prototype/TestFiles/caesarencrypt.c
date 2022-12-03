#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    for(int i = 0; i < testCases; i++){
        char string[100];
        int changes;
        scanf("%s %d", string, &changes);
        for(int i = 0; i < strlen(string); i++){
            if(isupper(string[i])){
                string[i] = string[i] + changes;
                if(string[i] > 'Z'){
                    string[i] -= 26;
                }
            } else {
                string[i] = string[i] + changes;
                if(string[i] > 'z'){
                    string[i] -= 26;
                }
            }
        }
        printf("Case #%d: %s\n", i + 1, string);
    }

    return 0;
}