#include <stdio.h>
#include <string.h>

void revstr(char *str1)  
{  
    // declare variable  
    int i, len, temp;  
    len = strlen(str1); // use strlen() to get the length of str string  
      
    // use for loop to iterate the string   
    for (i = 0; i < len/2; i++)  
    {  
        // temp variable use to temporary hold the string  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
} 

int main(){
    int testcase;
    scanf("%d", &testcase); getchar();
    for(int i = 0; i < testcase; i++){
        char string[1000];
        scanf("%[^\n]%*c", string);
        revstr(string);
        printf("Case #%d: %s\n", i+1, string);
    }
    return 0;
}