#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int testCases;
    scanf("%d", &testCases);
    getchar();
    for(int i = 0; i < testCases; i++){
        char string[101];
        char string2[101];
        scanf("%[^\n]", string);
        getchar();
        scanf("%[^\n]", string2);
        getchar();
        int len = strlen(string);
        int len2 = strlen(string2);

        for(int j = 0; j < len; j++){
            if(string[j] == ' '){
                
                for(int k = j; k < len; k++){
                    string[k] = string[k + 1];
                }
                len--;
            }
        }

        for(int j = 0; j < len2; j++){
            if(string2[j] == ' '){
                
                for(int k = j; k < len2; k++){
                    string2[k] = string2[k + 1];
                }
                len2--;
            }
        }
        // printf("Case #%d: %s\n", i + 1, string);
        // printf("Case #%d: %s\n", i + 1, string2);

        for(int j = 0; j < len; j++){
            string[j] = tolower(string[j]);
            string2[j] = tolower(string2[j]);
        }

        char chTemp;
        for(int k=0; k<len; k++)
        {
            for(int j=0; j<(len-1); j++)
            {
                if(string[j]>string[j+1])
                {
                    chTemp = string[j];
                    string[j] = string[j+1];
                    string[j+1] = chTemp;
                }
            }
        }

        for(int k=0; k<len2; k++)
        {
            for(int j=0; j<(len2-1); j++)
            {
                if(string2[j]>string2[j+1])
                {
                    chTemp = string2[j];
                    string2[j] = string2[j+1];
                    string2[j+1] = chTemp;
                }
            }
        }
        int flag = 0;

        for(int j = 0; j < len; j++){
            if(string[j] != string2[j]) flag = 1;
        }

        printf("Case #%d: %s\n", i + 1, string);
        printf("Case #%d: %s\n", i + 1, string2);
        if(flag) printf("NAY\n");
        else printf("YAY\n");

    }

    return 0;
}