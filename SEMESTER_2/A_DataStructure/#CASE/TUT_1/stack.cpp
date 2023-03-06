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

void popTail() {
    // If list is empty, do nothing
    if (head == NULL) {
        return;
    }
    
    // If list has only one node, free it and set head to NULL
    if ((head)->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    
    // Traverse to second-to-last node
    struct Node* curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    
    // Remove last node and update next pointer of second-to-last node
    free(curr->next);
    curr->next = NULL;
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
    popTail();
    pushTail(236);
    popTail();
    pushTail(798);
    pushTail(642);
    pushTail(412);
    pushTail(491);
    popTail();
    popTail();
    pushTail(250);
    pushTail(284);
    pushTail(607);
    popTail();
    pushTail(99);
    pushTail(275);
    pushTail(625);
    popTail();
    popTail();
    popTail();
    pushTail(997);
    pushTail(901);
    pushTail(82);
    popTail();
    popTail();
    pushTail(915);
    pushTail(480);
    pushTail(251);


    printlist();

    return 0;
}