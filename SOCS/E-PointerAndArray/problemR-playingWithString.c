#include <stdio.h>
#include <string.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    getchar();
    for(int i = 0; i < testCases; i++){
        char string[1001];
        int changes;

        scanf("%s", string);
        scanf("%d", &changes);
        getchar();
        for(int j = 0; j < changes; j++){
            char search, changewith;
            scanf("%c %c", &search, &changewith); getchar();
            for(int k = 0; k < strlen(string); k++){
                if(string[k] == search){
                    string[k] = changewith;
                }
            }
        }
        printf("Case #%d: %s\n", i + 1, string);
    }

    return 0;
}