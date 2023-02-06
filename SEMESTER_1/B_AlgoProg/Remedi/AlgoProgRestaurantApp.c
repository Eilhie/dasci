#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int EmpCounter = 0;
char EmpName[10][100];
char EmpStatus[10][100];
int EmpWorkingPeriod[10];
char EmpID[10][100];
long long int EmpInitialSalary[10];
long long int EmpProjectedSalary[10];
int EmpOrder[10];


int MenuCounter = 0;
char MenuName[50][100];
char MenuType[50][100];
int MenuPrice[50];
char MenuID[50][100];

int OrderQuantity[50];
int OrderCounter = 0;
char OrderID[50][100];
int OrderTable[50];
long long int OrderTotal[50];
long long int OrderSubTotal[50][50];
long long int OrderServices[50];
long long int OrderTax[50];
long long int OrderDiscount[50];
long long int OrderTotalPayment[50];
int OrderEmpIndex[50];
int OrderFood = 0;
int OrderBeverage = 0;

void MainMenu();

int main(){
    MainMenu();
    return 0;
}

void EmpView(){
    system("cls");
    printf("View Employee (%d)\n", EmpCounter);
    printf("-------------------------------------\n");
    for(int i = 0; i < EmpCounter; i++){
        printf("ID               : %s\n", EmpID[i]);
        printf("Name             : %s\n", EmpName[i]);
        printf("Status           : %s\n", EmpStatus[i]);
        printf("Working Period   : %d\n", EmpWorkingPeriod[i]);
        printf("Initial Salary   : %lld\n", EmpInitialSalary[i]);
        printf("Projected Salary : %lld\n\n", EmpProjectedSalary[i]);
    }
    printf("-------------------------------------\n > ");
    system("pause");
    MainMenu();
}

void EmpIDMaker(char name[]){
    char EMPID[100] = "";
    int len = strlen(name);
    char list[100][100];
    char *token = strtok(name, " ");
    int l = 0;
    while(token!=NULL){
        strcpy(list[l], token);
        token = strtok(NULL, " ");
        l++;
    }
    list[0][0] = toupper(list[0][0]);
    list[l - 1][0] = toupper((list[l - 1][0]));
    strncat(EMPID, list[0], 1);
    strncat(EMPID, list[l - 1], 1);

    char lens[10];
    sprintf(lens, "%02d",len);
    strcat(EMPID, lens);

    for(int i = 0; i < EmpCounter; i++){
        if(strcmp(EMPID, EmpID[i]) == 0){
            EMPID[strlen(EMPID) - 1] = '\0';
            EMPID[strlen(EMPID) - 1] = '\0';
            sprintf(lens, "%02d", (len + 1 + i));
            strcat(EMPID, lens);
        }
    }

    strcpy(EmpID[EmpCounter - 1], EMPID);
}

void EmpRegister(){
    char name[100];
    char status[100];
    int workingPeriod;
    long long int initialSalary;

    int run = 1;

    system("cls");
    printf("Employee Register\n");
    printf("-------------------------------------\n");
    
    while(run){
        printf("Name            : ");
        scanf("%[^\n]", name); getchar();
        
        int flag = 0;
        
        for(int i = 0; i < strlen(name); i++){
            if(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z' || name[i] == ' '){
                flag = 1;
            } else {
                flag = 0;
                break;
            }
        }
        if(flag){
            run = 0;
        }
    }
    run = 1;
    while (run){
        printf("Status          : ");
        scanf("%[^\n]", status); getchar();
        if(strcmp(status, "active") == 0|| strcmp(status, "inactive") == 0 || strcmp(status, "annual leave") == 0){
            break;
        }
    }
    
    
    printf("Working Period  : ");
    scanf("%d", &workingPeriod); getchar();
    printf("Initial Salary  : ");
    scanf("%lld", &initialSalary); getchar();
    printf("-------------------------------------\n > ");
    EmpCounter++;
    if(EmpCounter > 10){
        for(int i = 0; i < 10; i++){
            if(strcmp(EmpStatus[i], "inactive") == 0){
                strcpy(EmpName[i], name);
                strcpy(EmpStatus[i], status);
                EmpWorkingPeriod[i] = workingPeriod;
                EmpInitialSalary[i] = initialSalary;
                for(int j = 0; j < workingPeriod; j++){
                    initialSalary = initialSalary + round(initialSalary * 1.5 / 100);
                }
                EmpProjectedSalary[i] = initialSalary;
                EmpIDMaker(name);
            }
        }
    } else {
        strcpy(EmpName[EmpCounter - 1], name);
        strcpy(EmpStatus[EmpCounter - 1], status);
        EmpWorkingPeriod[EmpCounter - 1] = workingPeriod;
        EmpInitialSalary[EmpCounter - 1] = initialSalary;
        for(int i = 0; i < workingPeriod; i++){
            initialSalary = initialSalary + round(initialSalary * 1.5 / 100);
        }
        EmpProjectedSalary[EmpCounter - 1] = initialSalary;
        EmpIDMaker(name);
    }
    
    
    system("pause");
}

void EmpStatusChange(){
    char ID[100];
    char newStatus[100];
    system("cls");
    printf("Employee Status Change\n");
    printf("-------------------------------------\n");
    printf("ID : ");
    scanf("%s", ID); getchar();
    for(int i = 0; i < EmpCounter; i++){
        if(strcmp(ID, EmpID[i]) == 0){
            printf("ID               : %s\n", EmpID[i]);
            printf("Name             : %s\n", EmpName[i]);
            printf("Status           : %s\n", EmpStatus[i]);
            printf("Working Period   : %d\n", EmpWorkingPeriod[i]);
            printf("Initial Salary   : %lld\n", EmpInitialSalary[i]);
            printf("Projected Salary : %lld\n\n", EmpProjectedSalary[i]);
            printf("-------------------------------------\n");
            
            int run = 1;
            while (run){
                printf("Change Status to ?\n > ");
                scanf("%[^\n]", newStatus); getchar();
                if(strcmp(newStatus, "active") == 0|| strcmp(newStatus, "inactive") == 0 || strcmp(newStatus, "annual leave") == 0){
                    break;
                }
            }
            strcpy(EmpStatus[i], newStatus);
        } else if(strcmp(ID, EmpID[i]) != 0 && i == EmpCounter - 1) {
            printf("ERROR ->ID NOT FOUND!\n");
            system("pause");
            MainMenu();
        }
    }
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

void MenuIDMaker(char name[]){
    srand(time(0));
    char MENUID[100] = "";
    int n;
    char a = toupper(name[0]);
    char b = toupper(name[1]);
    strncat(MENUID, &a, 1);
    strncat(MENUID, &b, 1);
    n = rand() % 1000;
    char lens[100];
    sprintf(lens, "%03d", n);
    strcat(MENUID, lens);

    for(int i = 0; i < MenuCounter; i++){
        if(strcmp(MENUID, MenuID[i]) == 0){
            MENUID[strlen(MENUID) - 1] = '\0';
            MENUID[strlen(MENUID) - 1] = '\0';
            MENUID[strlen(MENUID) - 1] = '\0';
            n = rand() % 1000;
            sprintf(lens, "%03d", n);
            strcat(MENUID, lens);
        }
    }
    strcpy(MenuID[MenuCounter - 1], MENUID);
}

void MenuView(){
    system("cls");
    printf("View Menu (%d)\n", MenuCounter);
    printf("-------------------------------------\n");
    for(int i = 0; i < MenuCounter; i++){
        printf("ID               : %s\n", MenuID[i]);
        printf("Name             : %s\n", MenuName[i]);
        printf("Status           : %s\n", MenuType[i]);
        printf("Price            : %d\n\n", MenuPrice[i]);
    }
    printf("-------------------------------------\n > ");
    system("pause");
    MainMenu();
}

void MenuRegister(){
    char name[100];
    char type[100];
    long long int price;

    int run = 1;

    system("cls");
    printf("Menu Register\n");
    printf("-------------------------------------\n");
    
    while(run){
        printf("Name          : ");
        scanf("%[^\n]", name); getchar();
        
        int flag = 0;
        
        for(int i = 0; i < strlen(name); i++){
            if(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z' || name[i] == ' '){
                flag = 1;
            } else {
                flag = 0;
                break;
            }
        }
        if(flag){
            run = 0;
        }
    }
    run = 1;
    while (run){
        printf("Type          : ");
        scanf("%[^\n]", type); getchar();
        if(strcmp(type, "food") == 0|| strcmp(type, "beverage") == 0){
            break;
        }
    }
    
    printf("Price         : ");
    scanf("%lld", &price); getchar();
    printf("-------------------------------------\n > ");
    MenuCounter++;
    if(MenuCounter > 50){
        printf("ERROR ->LIST MAXED\n");
        system("pause");
        MainMenu();
    } else{
        strcpy(MenuName[MenuCounter - 1], name);
        strcpy(MenuType[MenuCounter - 1], type);
        MenuPrice[MenuCounter - 1] = price;
        MenuIDMaker(name);
    }
}

void MenuUpdate(){
    char ID[100];
    char newType[100];
    char newName[100];
    long long int newPrice;
    system("cls");
    printf("Menu Update\n");
    printf("-------------------------------------\n");
    printf("ID : ");
    scanf("%s", ID); getchar();
    for(int i = 0; i < MenuCounter; i++){
        if(strcmp(ID, MenuID[i]) == 0){
            printf("ID               : %s\n", MenuID[i]);
            printf("Name             : %s\n", MenuName[i]);
            printf("Type             : %s\n", MenuType[i]);
            printf("Price            : %d\n\n", MenuPrice[i]);
            printf("-------------------------------------\n");
            int run = 1;
            while(run){
                printf("Change Name TO ?\n > ");
                scanf("%[^\n]", newName); getchar();
                
                int flag = 0;
                
                for(int i = 0; i < strlen(newName); i++){
                    if(newName[i] >= 'a' && newName[i] <= 'z' || newName[i] >= 'A' && newName[i] <= 'Z' || newName[i] == ' '){
                        flag = 1;
                    } else {
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    run = 0;
                }
            }
            strcpy(MenuName[i], newName);
            run = 1;
            while (run){
                printf("Change Type to ?\n > ");
                scanf("%[^\n]", newType); getchar();
                if(strcmp(newType, "food") == 0|| strcmp(newType, "beverage") == 0){
                    break;
                }
            }
            strcpy(MenuType[i], newType);

            printf("Change Price to ?\n > ");
            scanf("%lld", &newPrice);
            MenuPrice[i] = newPrice;
            MenuIDMaker(newName);
            system("pause");
        } else if(strcmp(ID, MenuID[i]) != 0 && i == MenuCounter - 1) {
            printf("ERROR ->ID NOT FOUND!\n");
            system("pause");
            MainMenu();
        }
    }
}

void MenuManagement(){
    int run = 1;
    int select;
    do{
        system("cls");
        printf("Menu Management\n");
        printf("-------------------------------------\n");
        printf("1. View Menu\n");
        printf("2. Register Menu\n");
        printf("3. Update Menu\n");
        printf("0. Back To Main Menu\n");
        printf("-------------------------------------\n > ");
        scanf("%d", &select); getchar();

        switch (select){
            case 1:
                MenuView();
                break;
            case 2:
                MenuRegister();
                break;
            case 3:
                MenuUpdate();
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

void OrderIDMaker(){
    char orderID[100] = "ORD";
    char lens[100];
    sprintf(lens, "%02d", OrderCounter);
    strcat(orderID, lens);
    strcpy(OrderID[OrderCounter - 1], orderID);
}

void OrderSystemGenerate(){
    OrderTable[OrderCounter - 1] = OrderCounter;
    OrderIDMaker();
    printf("\n\nSystem Generate\n");
    printf("-------------------------------------\n");
    printf("ID : %s\n", OrderID[OrderCounter - 1]);
    printf("TableNumber : %d\n", OrderTable[OrderCounter - 1]);
    OrderTotal[OrderCounter - 1] = 0;
    for(int i = 0; i < 50; i++){
        OrderSubTotal[OrderCounter - 1][i] = OrderQuantity[i] * MenuPrice[i];
        OrderTotal[OrderCounter - 1] += OrderSubTotal[OrderCounter - 1][i];
        if(OrderSubTotal[OrderCounter - 1][i] != 0){
            printf("SubTotal : %lld\n", OrderSubTotal[OrderCounter - 1][i]);
        }
    }
    printf("Total : %lld\n", OrderTotal[OrderCounter - 1]);
    OrderServices[OrderCounter - 1] = OrderTotal[OrderCounter - 1] * 5 / 100;
    printf("Services : %lld\n", OrderServices[OrderCounter - 1]);
    OrderTax[OrderCounter - 1] = (OrderTotal[OrderCounter - 1] + OrderServices[OrderCounter - 1]) * 10 / 100;
    printf("Tax : %lld\n", OrderTax[OrderCounter - 1]);
    int multi = floor(OrderTotal[OrderCounter - 1] / 500000);
    OrderDiscount[OrderCounter - 1] = OrderTotal[OrderCounter - 1] * (multi * 2.5) / 100;
    printf("Discount : %lld\n", OrderDiscount[OrderCounter - 1]);
    OrderTotalPayment[OrderCounter - 1] = OrderTotal[OrderCounter - 1] + OrderServices[OrderCounter - 1] + OrderTax[OrderCounter - 1] - OrderDiscount[OrderCounter - 1];
    printf("Total Payment : %lld\n", OrderTotalPayment[OrderCounter - 1]);

}

void OrderCreateNew(){
    char empID[100];
    char menuID[100];
    int quant;
    for(int i = 0; i < 50; i++){OrderQuantity[i] = 0;}
    for(int i = 0; i < 10; i++){EmpOrder[i] = 0;}
    system("cls");
    printf("Create New Order\n");
    printf("-------------------------------------\n");
    printf("Employee ID : ");
    scanf("%s", empID); getchar();
    for(int i = 0; i < EmpCounter; i++){
        if(strcmp(empID, EmpID[i]) == 0){
            EmpOrder[i] += 1;
            OrderEmpIndex[OrderCounter] = i;
            printf("Menu ID : ");
            scanf("%s", menuID); getchar();
            for(int j = 0; j < MenuCounter; j++){
                if(strcmp(menuID, MenuID[j]) == 0){
                    if(strcmp("beverage", MenuType[j]) == 0){
                        OrderBeverage += 1;
                    } else {
                        OrderFood += 1;
                    }
                    printf("Quantity : ");
                    scanf("%d", &quant); getchar();
                    if(quant > 50 || OrderCounter > 50){
                        printf("ERROR -> ORDERLIMIT EXCEDED\n");
                        system("pause");
                        MainMenu();
                    } else {
                        if(OrderQuantity[j] > 50){
                            printf("ERROR -> ORDERLIMIT EXCEDED\n");
                        } else {
                            OrderCounter++;
                            OrderQuantity[j] += quant;
                            OrderSystemGenerate();
                            system("pause");
                        }
                    }
                }
            }
        }
    }
}

void OrderViewHistory(){
    system("cls");
    printf("View Order History\n");
    printf("-------------------------------------\n");
    int len = 0;
    if(OrderCounter > 5){
        len = 5;
    } else {
        len = OrderCounter;
    }
    for(int i = 0; i < len; i++){
        printf("ID : %s\n", OrderID[i]);
        printf("TableNumber : %d\n", OrderTable[i]);
        printf("Employer Name : %s\n", EmpName[OrderEmpIndex[i]]);
        OrderTotal[i] = 0;
        for(int j = 0; j < 50; j++){
            OrderSubTotal[i][j] = OrderQuantity[j] * MenuPrice[j];
            OrderTotal[i] += OrderSubTotal[i][j];
            if(OrderSubTotal[i][j] != 0){
                printf("SubTotal : %lld\n", OrderSubTotal[i][j]);
            }
        }
        printf("Total : %lld\n", OrderTotal[i]);
        OrderServices[i] = OrderTotal[i] * 5 / 100;
        printf("Services : %lld\n", OrderServices[i]);
        OrderTax[i] = (OrderTotal[i] + OrderServices[i]) * 10 / 100;
        printf("Tax : %lld\n", OrderTax[i]);
        int multi = floor(OrderTotal[i] / 500000);
        OrderDiscount[i] = OrderTotal[i] * (multi * 2.5) / 100;
        printf("Discount : %lld\n", OrderDiscount[i]);
        OrderTotalPayment[i] = OrderTotal[i] + OrderServices[i] + OrderTax[i] - OrderDiscount[i];
        printf("Total Payment : %lld\n\n\n", OrderTotalPayment[i]);
    }
    system("pause");
}

void OrderManagement(){
    int run = 1;
    int select;
    do{
        system("cls");
        printf("Order Management\n");
        printf("-------------------------------------\n");
        printf("1. View Order History\n");
        printf("2. Create New Order\n");
        printf("0. Back To Main Menu\n");
        printf("-------------------------------------\n > ");
        scanf("%d", &select); getchar();

        switch (select){
            case 1:
                OrderViewHistory();
                break;
            case 2:
                OrderCreateNew();
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

void DailyReport(){
    long long int totalTransaction = 0;

    int index = 0;
    int max = EmpOrder[0];
    for(int i = 1; i < 10; i++){
        if(max < EmpOrder[i]){
            max = EmpOrder[i];
            index = i;
        }
    }

    system("cls");
    printf("Daily Report\n");
    printf("-------------------------------------\n");
    printf("Total Order : %d\n", OrderCounter);
    printf("Total Ordered Food : %d\n", OrderFood);
    printf("Total Ordered Beverage : %d\n", OrderBeverage);
    for(int i = 0; i < OrderCounter; i++){
        totalTransaction += OrderTotalPayment[i];
    }
    printf("Total Transaction : %lld\n", totalTransaction);
    printf("MVE : %s\n", EmpName[index]);

    system("pause");
    MainMenu();
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
                MenuManagement();
                break;
            case 3:
                OrderManagement();
                break;
            case 4:
                DailyReport();
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
