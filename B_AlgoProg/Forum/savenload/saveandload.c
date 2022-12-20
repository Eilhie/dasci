#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int filecheck(const char *file_name);
int confirmation(char x);
void savemode();
void save();
void loadmode();
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

void savemode(){
    FILE *fp = fopen("savedata.in", "a+");
    int line_count = 0;
    int conf;
    char x;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), fp) != NULL){
        line_count++;
    }
    do{
        printf("Type some text to be saved. . .\n > ");
        scanf("%[^\n]", buffer); getchar();
        fprintf(fp, "%d %s\n", line_count + 1, buffer);
        printf("do you want to save another text? (Y/n)\n > ");
        scanf("%c", &x); getchar();
        conf = confirmation(x);
        if(conf == 0) break;
    } while(conf < 0);
    
    system("pause");
    MainMenu();
    
    fclose(fp);
}

void save(){
    char x;
    int conf;
    int nums = 0;
    system("cls");
    printf("SAVE\n");
    printf("-------------------------------------\n");
    if(filecheck("savedata.in")) {
        printf("There is no saved data!\n");
    } else 
        printf("Saved data Found!\n");    

    do{
        printf("do you want to add data to file? (Y/n)\n > ");
        scanf("%c", &x); getchar();
        conf = confirmation(x);
    } while(conf < 0); 
    if(conf == 1) savemode();
    else MainMenu();

    system("pause");
    MainMenu();
}

void loadmode(){
    FILE *fp = fopen("savedata.in", "r");
    int line_count = 0;
    int conf, loaded;
    char x;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), fp) != NULL){
        line_count++;
    }
    for(int i = 1; i <= line_count; i++){
        if(i % 5 == 0) printf(" %d\n", i);
        else printf(" %d ", i);
    }
    puts("");
    do{
        do{
            printf("Select Data to be Loaded\n > ");
            scanf("%d", &loaded); getchar();
        }while(loaded < 0 || loaded > line_count);

        int count = 0;
        while (fgets(buffer, sizeof(buffer), fp) != NULL){
            count++;
            if (count == loaded){
                fgets(buffer, sizeof(buffer), fp);
                break;
            }
        }
        printf("%s\n", buffer);
    
        if(line_count > 1){
            printf("do you want to Load another text? (Y/n)\n > ");
            scanf("%c", &x); getchar();
            conf = confirmation(x);
            if(conf == 0) break;
        } else break;
    } while(conf < 0);

    fclose(fp);
    system("pause");
    MainMenu();
}

void load(){
    
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
        printf("Saved data found\n");

        do{
            printf("do you want to load the data? (Y/n)\n > ");
            scanf("%c", &x); getchar();
            conf = confirmation(x);
        } while(conf < 0); 
        if(conf == 1) loadmode();
        else MainMenu();
    }
    system("pause");
    MainMenu();
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