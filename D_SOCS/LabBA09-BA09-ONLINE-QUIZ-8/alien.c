#include <stdio.h>

int main(){

    char word[3][50];
    char word2[3][50];
    scanf("%s %s %s", word[0], word[1], word[2]);
    scanf("%s %s %s", word2[0], word2[1], word2[2]);
    printf("%sszs %sszs %sszs\n", word[0], word[1], word[2]);
    printf("%sszs %sszs %sszs\n", word2[0], word2[1], word2[2]);

    return 0;
}