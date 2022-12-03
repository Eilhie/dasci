#include <stdio.h>

int main(){
    char kata[100];
    scanf("%[^\n]", kata);

    printf("Congrats \"%s\" for joining the CS department at BINUS.\n",kata);
}