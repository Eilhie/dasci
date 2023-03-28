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

void add(){
    char name[225];
    char email[225];

    bool error = true; // error checker

    //validasi nama , 1-50, lebih dari 2 kata
    while(error){
        printf("NAME : ");
        scanf("%[^\n]", name); getchar();

        if(strlen(name) >= 1 && strlen(name) <= 50 && strchr(name, ' ')) error = false;
    }
    error = true;

    while(error){
        printf("EMAIL : ");
        scanf("%[^\n]", email); getchar();

        //validasi hanya ada 1 simbol @, posisi harus @[domain].com
        // posisi @ tidak bolh paling dpn

        int occur = 0;
        for(int i = 0; email[i] != '\0'; i++){
            if(email[0] == '@')
                break; 
            else if(email[i] == '@') occur++;
        }
        if(occur == 1 && (strstr(email, "@") + 1< strstr(email, ".com"))) error = false;
    }

    push(name, email);
}

int main(){
    srand(time(NULL));
    push("mrvn", "mrvn@mail.cm");
    push("mrvn", "rvn@mail.cm");
    push("mrvn", "zion@mail.cm");
    add();
    printAll();
    return 0;
}