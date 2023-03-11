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
    int cusIDNum = rand() %1000;
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

void pushTail(const char *name, int price){
    if(head == NULL) {
        head = tail = createNode(name, price);
    } else {
        food *node = createNode(name, price);
        tail->next = node;
        node->prev = tail;
        tail = node;
        tail->next = NULL;
    }
}

void pushMid(const char *name, int price) {
    if(head == NULL) {
        head = tail = createNode(name, price);
    } else if(strcmp(name, head->foodName) > 0){
        pushHead(name, price);
    } else if(strcmp(name, tail->foodName) < 0){
        pushTail(name, price);
    } else {
        food *curr = head;
        food *node = createNode(name, price);
        while(curr != tail && strcmp(name, curr->foodName) > 0){
            curr = curr->next;
        }
        food *before = curr->prev;
        before->next = node;
        node->prev = before;

        curr->prev = node;
        node->next = curr;


    }
}

void popHead(){
    if(head == NULL) {
        return;
    } else {
		food* toFree = head;
		head = head->next;
		free(toFree);
		toFree = NULL;
	}
    
}

void popTail(){
    if(head == NULL) return;
	
	if(head == tail) {
		free(head);
		head = tail = NULL;
	} else {
		food* current = head;
		while(current->next != tail) current = current->next;
		tail = current;
		
		free(current->next);
		current->next = NULL;
	}
	
}

void popMid(int price) {
	if (!head) {
		return;
	}
	else {
		if (head->price == price){
			popHead();
			
		}
		else if(tail->price == price) {
			popTail();
		}
		else{
			food* current = head;
			while(current) {
				if(current->price == price) {
					break;
				}
				current = current->next;
			}
			
			if(!current) {
				printf("price tidak ada.\n");
				return;
			}
			
			else {
				food *toDelete = current->next;
				current->prev->next = current->next;
				current->next->prev = current->prev;
				free(toDelete);
				return;
			}
			
		}
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
    pushTail("STEAK", 500000);
    pushMid("PIZZA", 100000);
    printall();

    return 0;
}