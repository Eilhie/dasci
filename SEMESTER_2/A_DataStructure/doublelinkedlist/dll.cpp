#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct food{
    char foodID[10]; // incremental
    char foodName[225];
    int foodPrice;
    char cusID[10]; // random
    food *next;
    food *prev;
} *head, *tail;

int id = 1;

food *createNode(const char *name, int price){
    food *temp = (food*)malloc(sizeof(food));
    strcpy(temp->foodName, name);
    temp->foodPrice = price;
    temp->next = NULL;
    temp->prev = NULL;

    char foodIDTemp[10];
    sprintf(foodIDTemp, "FD%03d", id);
    id++;
    strcpy(temp->foodID, foodIDTemp);

    char cusIDTemp[10];
    int cusIDNum = rand() %100;
    sprintf(cusIDTemp, "CS%03d", cusIDNum);
    strcpy(temp->cusID, cusIDTemp);

    return temp;
}

void pushHead(const char *name, int price){
    if(head == NULL) {
        head = tail = createNode(name, price);
    } else {
        food *node = createNode(name, price);
        head->prev = node;
        node->next = head;
        head = node;
        head->prev = NULL;
    }
}

void printall(){
    food *curr = head;
    while(curr != NULL){
        printf("%s %s %s %d\n", curr->foodID, curr->foodName, curr->cusID, curr->foodPrice);
        curr = curr->next;
    }
}

int main(){

    pushHead("BURGER", 50000);
    pushHead("WORTEL", 50000);
    pushHead("SOSIS", 50000);

    printall();

    return 0;
}