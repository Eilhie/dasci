#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int value;
    int level;

    Node *next;
    Node *prev;
} *head, *tail;

Node *createNode(int value, char *prior)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = value;

    if (strcmp(prior, "VVIP") == 0)
        temp->level = 3;
    else if (strcmp(prior, "VIP") == 0)
        temp->level = 2;
    else
        temp->level = 1;

    temp->next = temp->prev = NULL;

    return temp;
}

void insert(){
    int value;
    char prior[225];

    printf("masukan value : ");
    scanf("%d", &value); getchar();
    printf("masukan tingkat membership : ");
    scanf("%[^\n]", prior); getchar();

    Node* toPush = createNode(value, prior);

    if(head == NULL) head = tail = toPush;
    if(head->level < toPush->level){
        // push head
        toPush->next = head;
        head->prev = toPush;
        head = toPush;
    } else if (tail->level >= toPush->level) {
        // push tail
        toPush->prev = tail;
        tail->next = toPush;
        tail = toPush;
    } else {
        // push mid
        Node *curr = head;
        while (curr != NULL && curr->level >= toPush->level){
            curr = curr->next;
        }
        toPush->next = curr;
        toPush->prev = curr->prev;
        curr->prev = toPush;
        toPush->prev->next = toPush;
    }
}

void popHead(){
    if(head == NULL){
        puts("KOSONG");
    } else if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
}