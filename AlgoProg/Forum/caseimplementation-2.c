#include <stdio.h>
#include <string.h>

int main(){

    char string[1000];
    int input, index = 0;
    char history[10][1000];

    menu:

    system("cls");
    printf("Schedule\n");
    printf("=----------------------=\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Show History\n");
    printf("0. Exit\n");
    printf("=----------------------=\n> ");

    scanf("%d", &input); getchar();

    if(input == 1){
        system("cls");
        printf("ENCRYPT\n");
        printf("=----------------------=\n");
        printf("Input string to Encrypt\n> ");
        scanf("%[^\n]", string); 

        for(int i = 0; i < strlen(string); i++){
            string[i] = string[i] + 9;
        }
        printf("ENCRYPTED : %s\n", string);
        strcpy(history[index], string);
        index++;
        system("pause");
        goto menu;
    } else if(input == 2){
        system("cls");
        printf("DECRYPT\n");
        printf("=----------------------=\n");
        printf("Input string to Encrypt\n> ");
        scanf("%[^\n]", string); 

        for(int i = 0; i < strlen(string); i++){
            string[i] = string[i] - 9;
        }
        printf("DECRYPTED : %s\n", string);
        system("pause");
        goto menu;
    } else if(input == 3){
        system("cls");
        printf("HISTORY OF ENCRYPTION\n");
        printf("=----------------------=\n");
        for(int i = 0; i < index; i++){
            printf("%d. %s\n", i + 1, history[i]);
        }
        printf("=----------------------=\n");
        system("pause");
        goto menu;
    } else if (input == 0){
        printf("Terminating System\n");
    }

    return 0;
}