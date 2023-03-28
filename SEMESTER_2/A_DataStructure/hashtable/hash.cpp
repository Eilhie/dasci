#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10
// HashTable Chaining 
struct Node {
    char ID[10];
    char name[225];
    char email[50];

    Node *next;
    Node *prev;
} *head[SIZE], *tail[SIZE];

Node* createNode(char* name, char* email){
    Node* temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->name, name);
    strcpy(temp->email, email);

    // ID CREATING
    sprintf(temp->ID, "ST%03d", rand() % 1000);

    temp->next = temp->prev = NULL;

    return temp;
}

int hash(char* name){
    int hashed = 0;
    for(int i = 0; i < strlen(name); i++){
        hashed += name[i];
    }
    return hashed % SIZE;
}

void push(char* name, char* email){
    Node* temp = createNode(name, email);
    int index = hash(name);

    if(head[index] == NULL) head[index] = tail[index] = temp;
    else {
        tail[index]->next = temp;
        temp->prev = tail[index];
        tail[index] = temp;
    }
}

void printAll(){
    for(int i = 0; i < SIZE; i++){
        Node* curr = head[i];
        printf("%d\n", i);
        while(curr != NULL) {
            printf("%s %s %s\n", curr->ID, curr->name, curr->email);
            curr = curr->next;
        }
        puts("");
    }
}

int main(){
    srand(time(NULL));
    push("mrvn", "mrvn@mail.cm");
    push("mrvn", "rvn@mail.cm");
    push("mrvn", "zion@mail.cm");

    printAll();
    return 0;
}