#include <stdio.h>

int main(){

    char schedule[1000][1000];
    int input, count = 0;
    menu :
    system("cls");
    printf("Schedule\n");
    printf("=----------------------=\n");
    printf("1. Add Schedule\n");
    printf("2. Show Schedule\n");
    printf("3. Exit\n");
    printf("=----------------------=\n> ");
    
    scanf("%d", &input); getchar();

    if(input == 1){
        system("cls");
        printf("=----------------------=\n");
        printf("Date, Plan Description\n > ");
        scanf("%[^\n]", schedule[count]); //putting schedule to array 
        count++;
        goto menu;
    } else if(input == 2){
        printf("=----------------------=\n");
        for(int i = 0; i < count; i++){
            printf("%d %s\n",i + 1, schedule[i]); //show every entry of the schedule to console
        }
        system("pause");
        goto menu;
    } else if (input == 3){
        printf("Terminating System\n");
    }
    
    return 0;
}