#include <stdio.h>
#include <string.h>

int main(){

char str[100], chTemp, postemp;
    int len;
    char position[100] = {"1 2 3"};    
    
    gets(str);
    len = strlen(str);
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<(len-1); j++)
        {
            if(str[j]>str[j+1])
            {
                chTemp = str[j];
                postemp = position[j];
                
                str[j] = str[j+1];
                position[j] = position[j+1];
                str[j+1] = chTemp;
                position[j+1] = postemp;
            }
        }
    }
    printf("%c %c %c\n", position[2], position[3], position[4]);

    return 0;
}