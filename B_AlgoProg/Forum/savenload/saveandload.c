#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int filecheck(const char *file_name);
int confirmation(char x);
void save();
void load();
void MainMenu();

int main(){
    MainMenu();
    return 0;
}

int filecheck(const char *file_name){
    FILE *fp = fopen(file_name, "r");
    long pos;
    if (fp == NULL)
        return 1;
    
    fseek(fp, 0, SEEK_END);
    pos = ftell(fp);
    if (pos == 0)
        return 1;
    else 
        return 0;
    
    fclose(fp);
}

int confirmation(char x){
    if(x == 'y' || x == 'Y') return 1;
    else if(x == 'n' || x =='N') return 0;

    return -1;
}

void save(){
    FILE *fp = fopen("savedata.in", "a");

    system("cls");
    printf("SAVE\n");
    printf("-------------------------------------\n");
    

    fclose(fp);
    index++;
}

void load(){
    FILE *fp = fopen("savedata.in", "a");
    char x;
    int conf;

    system("cls");
    printf("LOAD\n");
    printf("-------------------------------------\n");
    if(filecheck("savedata.in")) {
        printf("There is no saved data!\n");
        
        do{
            printf("do you want to add data to file? (Y/n)\n > ");
            scanf("%c", &x); getchar();
            conf = confirmation(x);
        } while(conf < 0); 
        if(conf == 1) save();
        else MainMenu();
    }
    else {
        printf("file is not empty\n");
    }
    MainMenu();
    fclose(fp);
}

void MainMenu(){
    int run = 1;
    int select;
    do{
        system("cls");
        printf("SAVE / LOAD\n");
        printf("-------------------------------------\n");
        printf("1. Save\n");
        printf("2. Load\n");
        printf("0. EXIT\n");
        printf("-------------------------------------\n > ");
        scanf("%d", &select); getchar();

        switch (select){
            case 1:
                save();
                break;
            case 2:
                load();
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