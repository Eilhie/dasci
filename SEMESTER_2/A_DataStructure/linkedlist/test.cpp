#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
}Node;

Node *head, *tail;      //HEAD TAIL GLOBAL

struct Node* createNode(char data){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void pushTail(char data){
    if (head == NULL){
        head = createNode(data);
        return; //matiin function
    }
    Node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = createNode(data);
}

char popTail(){
    if(head == NULL){
        printf("\nStack is empty!\n\n");
        return NULL;
    }
    Node *temp = head;
    char res;
    if (head->next == NULL){
        res = head->data;
        free(head);
        head = NULL;
        return res;
    }

    while (temp->next->next != NULL){
        temp = temp->next;
    }
    res = temp->data;
    free(temp->next);
    temp->next = NULL;
    return res;
}

int isMatching(char key1, char key2){
    if(key1 == '(' && key2 == ')') return 1;
    if(key1 == '[' && key2 == ']') return 1;
    if(key1 == '{' && key2 == '}') return 1;
    else return 0;
}

void printlist(){
    Node* curr = head;
    while(curr != NULL) {
        printf("%c ", curr->data);
        curr = curr->next;
    }
    puts("");
}

int isBalance(char input[]){
    int i = 0;
    while(i < strlen(input)){
        if(input[i] == '(' || input[i] == '{' || input[i] == '[') pushTail(input[i]);
        if(input[i] == ')' || input[i] == '}' || input[i] == ']') {
            if(head == NULL) return 0;
            else if(!isMatching(popTail(), input[i])) return 0;
        }
        // printlist();
        i++;
    }
    if(head == NULL) return 1;
    else return 0;
}

int main (){
    char input[100];
    printf("Masukkan Pola: ");
    scanf("%[^\n]", input); getchar(); 

    if(strcmp("-1", input) == 0) {
        puts("bye");
    } else {
        puts("inputted");
        if(isBalance(input)) puts("BALANCE");
        else puts("BALANCE BREAKER");
        
    }

    /*
    
    

    */


}