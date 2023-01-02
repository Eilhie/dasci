#include <stdio.h>

const char *mode = "a+";

void mainMenu();
void addItems();
int filecheck(const char *file_name);
int confirmation(char x);
void displayInventory();
int main(){
    
    if(filecheck("inventory.dat")) {
        FILE *fp = fopen("inventory.dat", mode);
        printf("There is no saved data!\n");
        fprintf(fp, "index\tName\t\tQuantity\n");
        fclose(fp);
    }
    
    mainMenu();
    
    return 0;
}

// Program Inventory 
// menu 1: input semua barang & quantity

// menu 2: display inventory sejauh ini

// menu 3: sort berdasarkan nama barang (alphabetical)

// menu 4: sort quantity dari paling gede

int filecheck(const char *file_name){
    FILE *fp = fopen(file_name, mode);
    long pos;
    if (fp == NULL)
        return 1;
    
    fseek(fp, 0, SEEK_END);
    pos = ftell(fp);
    fclose(fp);
    if (pos == 0)
        return 1;
    else 
        return 0;
}

int confirmation(char x){
    if(x == 'y' || x == 'Y') return 1;
    else if(x == 'n' || x =='N') return 0;

    return -1;
}

void displayInventory(){
    FILE *fp = fopen("inventory.dat", "r");
    char ch;

    while (!feof(fp)) {
        ch = fgetc(fp);
        printf("%c", ch);
    }

   fclose(fp);
    mainMenu();
}

void addItems(){
    int line_count = 0, quantity = 0;
    int conf;
    char x;
    char buffer[1024];
    FILE *fp = fopen("inventory.dat", mode);

    while (fgets(buffer, sizeof(buffer), fp) != NULL){
        line_count++;
    }
    do{
        printf("Item Name :  ");
        scanf("%[^\n]", buffer); getchar();
        printf("Quantity  :  ");
        scanf("%d", &quantity); getchar();
        fprintf(fp, "\n%d\t%s\t\t%d", line_count, buffer, quantity);
        printf("do you want to add more item? (Y/n)\n > ");
        scanf("%c", &x); getchar();
        conf = confirmation(x);
        if(conf == 0) break;
    } while(conf < 0); 

    fclose(fp);
}

void mainMenu(){

    int option, run = 1;
    do{
        printf("\n\n1. Add Items\n2. Display Inventory\n0. Exit\n");
        printf("> ");
        scanf("%d", &option); getchar();

        switch(option){
        case 1:
            addItems();
            break;
        case 2:
            displayInventory();
            break;
        case 0:
            run = 0;
            break;
        default:
            printf("ERROR-> Input NOT Valid!\n");
        }
    } while(run);
    

}