#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee{
    int index;
    char *plan;
};

void EmployeeManagement();
void MainMenu();

int main(){  
    MainMenu();
    return 0;
}

void EmployeeManagement(){
int run = 1;
    int select;
    do{
        system("cls");
        printf("Employee Management\n");
        printf("-------------------------------------\n");
        printf("1. View Employee\n");
        printf("2. Register Employee\n");
        printf("3. Change Status\n");
        printf("0. Back To Menu\n");
        printf("-------------------------------------\n > ");
        scanf("%d", &select); getchar();

        switch (select){
            case 1:
                EmpView();
                break;
            case 2:
                EmpRegister();
                break;
            case 3:
                EmpStatusChange();
                break;
            case 0:
                MainMenu();
                break;
            default:
                printf("ERROR-> Input NOT Valid!\n");
            break;
        } 
    } while (run);
}

void MainMenu(){
    int run = 1;
    int select;
    do{
        system("cls");
        printf("Main Menu\n");
        printf("-------------------------------------\n");
        printf("1. Employee Management\n");
        printf("2. Menu Management\n");
        printf("3. Order Management\n");
        printf("4. Daily Report\n");
        printf("0. EXIT\n");
        printf("-------------------------------------\n > ");
        scanf("%d", &select); getchar();

        switch (select){
            case 1:
                EmployeeManagement();
                break;
            case 2:
                //MenuManagement();
                break;
            case 3:
                //OrderManagement();
                break;
            case 4:
                //DailyReport();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("ERROR-> Input NOT Valid!\n");
            break;
        } 
    } while (run);
}