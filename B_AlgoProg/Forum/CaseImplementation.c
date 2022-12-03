#include <stdio.h>

int main(){

    char schedule[1000];
    int input;
    menu :
    system("cls");
    printf("Schedule\n");
    printf("=----------------------=\n");
    printf("1. Add Schedule\n");
    printf("2. Show Schedule\n");
    printf("3. Exit\n");
    printf("=----------------------=\n > ");
    
    scanf("%d", &input); getchar();

    if(input == 1){
        system("cls");
        printf("=----------------------=\n");
        printf("Date, Plan Description\n > ");
        scanf("%[^\n]", schedule); 
        goto menu;
    } else if(input == 2){
        printf("=----------------------=\n");
        printf("%s\n", schedule);
        system("pause");
        goto menu;
    } else if (input == 3){
        printf("Terminating System\n");
    }
    
    return 0;
}