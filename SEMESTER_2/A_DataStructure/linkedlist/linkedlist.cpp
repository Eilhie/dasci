#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    char grade;
    Node *next;
} *head;

Node* createNode(int data, char grade) {
    Node *temp = (Node*)malloc(sizeof(Node)); // create a temp node
    temp->data = data; // fill the data
    temp->grade = grade;

    temp->next = NULL; // next fill with null

    return temp;
}

void pushHead(int data, char grade) {
    Node* newnode = createNode(data, grade);

    newnode->next = head;

    head = newnode;
}

void pushTail(int data, char grade){
    Node* temp = createNode(data, grade);

    Node* curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
}

void printlist(){
    Node* current = head;
    while (current != NULL) {
        printf("%d %c\n", current->data, current->grade);
        current = current->next;
    } 
}

void searchlist(int data) {
    Node* current = head;
    while (current != NULL){
        if(current->data == data){
            puts("FOUND");
            return;
        }
        current = current->next;
    }
    puts("NOT FOUNDED");
}

void deleteAll(){
    head = NULL;
}

void popHead(){
    if(head == NULL) return;

    Node* old = head;
    head = head->next;
    free(old);
}

int main(){

    pushHead(10, 'A');
    pushHead(5, 'C');
    pushTail(15, 'D');

    

    //printlist();

    // searchlist(20);
    // searchlist(5);
    // deleteAll();
    popHead();
    printlist();
    puts("END");
    return 0;
}