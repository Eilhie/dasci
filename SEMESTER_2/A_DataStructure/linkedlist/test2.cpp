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

int popHead() {
    // If list is empty, do nothing
    if (head == NULL) {
        return 0;
    }

    if(head){
        free(head);
        head = NULL;
        return 0;
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
    int input;
    int run = 1;
    do{
        puts("input -1 to exit!!");
        printf("number : ");
        scanf("%d", &input); getchar();

        if(input == -1) return 0;

        if(head == NULL || head->data <= input){
            for(int i = 0; i < input; i++){
                int enque;
                printf("enque : ");
                scanf("%d", &enque); getchar();
                pushTail(enque);
            }
        } else if (head->data > input){
            for(int i = 0; i < input; i++) {
                int stop = popHead();
                if(stop == 0) break;
            }
        }
        // getchar();
        // char confirm;
        // printf("CONTINUE (Y/n)? ");
        // scanf("%c", confirm); getchar();

        // if(confirm == 'y' || confirm == 'Y') run = 1;
        // else run = 0;

        printlist();

    } while (run == 1);
    
    
    return 0;
}