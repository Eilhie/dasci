#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    Node* next;
} *head, *tail;

Node* createNode(int data){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void popHead() {
    // If list is empty, do nothing
    if (head == NULL) {
        return;
    }
    
    // Save current head node and update head pointer
    struct Node* oldHead = head;
    head = head->next;
    
    // Free old head node
    free(oldHead);
}

void pushTail(int val) {
    // Create new node
    struct Node* newNode = createNode(val);
    
    // If list is empty, set new node as head
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    // Traverse to end of list
    struct Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    // Add new node to end of list
    curr->next = newNode;
}


void printlist(){
    Node* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    puts("");
}

int main(){

    pushTail(309);
    pushTail(351);
    pushTail(663);
    popHead();
    pushTail(236);
    popHead();
    pushTail(798);
    pushTail(642);
    pushTail(412);
    pushTail(491);
    popHead();
    popHead();
    pushTail(250);
    pushTail(284);
    pushTail(607);
    popHead();
    pushTail(99);
    pushTail(275);
    pushTail(625);
    popHead();
    popHead();
    popHead();
    pushTail(997);
    pushTail(901);
    pushTail(82);
    popHead();
    popHead();
    pushTail(915);
    pushTail(480);
    pushTail(251);


    printlist();

    return 0;
}