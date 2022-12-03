#include <stdio.h>

void strnng(char line[], int testCases){

   for (int i = 0, j; line[i] != '\0'; ++i) {
      while (!(line[i] >= 'a' && line[i] <= 'z') && !(line[i] >= 'A' && line[i] <= 'Z') && !(line[i] == '\0')) {
         for (j = i; line[j] != '\0'; ++j) {

            line[j] = line[j + 1];
         }
         line[j] = '\0';
      }
   }
   printf("Case #%d: ", testCases);
   puts(line);
}


int main(){

    int testCases;

    scanf("%d", &testCases);
    
    for(int k = 0; k < testCases; k++){
        char string[100];
        int lenght;
        scanf("%d", &lenght);getchar();
        scanf("%[^\n]", string);
        strnng(string, k+1);
    }

    return 0;
}