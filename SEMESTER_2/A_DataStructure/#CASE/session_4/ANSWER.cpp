#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 1007

struct Node{
    char ID[255];
    char title[225];
    char author[225];
    char ISBN[225];
    int pnum;
} *table[size];

Node* createNode(char* ID, char* title, char* author, char* ISBN, int pnum){
    Node *temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->ID, ID);
    strcpy(temp->author, author);
    strcpy(temp->ISBN, ISBN);
    strcpy(temp->title, title);
    temp->pnum = pnum;

    return temp;
}

int hash(char* key){
    int sum = 0;
    for(int i = 0; i < strlen(key); i++){
        sum += key[i];
    }
    return sum % size;
}

void insert(){
    int index = hash(key);
}

void view(){

}

int main(){
    int run = 1, input;
    do{
        do{
            printf("BLUEJACK HOSPITAL\n");
            printf("=================\n");
            printf("1. View\n");
            printf("2. Insert\n");
            printf("3. Delete\n");
            printf("4. Exit\n");
            printf(">>");
            scanf("%d", &input); getchar();
        } while (input > 4 || input < 0);
        switch (input){
            case 1:
                view();
                break;
            case 2:
                break;
            case 3:
                // nextQ();
                break;
            case 4:
                run = 0;
                break;
        }
    }while(run);
    return 0;
}