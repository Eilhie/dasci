#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define size 10

struct Node
{
    int value;
    Node *next;
    Node *prev;
} *head[size], *tail[size];

Node *createNode(int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = value;
    temp->next = temp->prev = NULL;

    return temp;
}
int hash(int value)
{
    return value % size;
}

void push(int value)
{
    Node *temp = createNode(value);
    int index = hash(value);
    if (head[index] == NULL)
        head[index] = tail[index] = temp;
    else
    {
        tail[index]->next = temp;
        temp->prev = tail[index];
        tail[index] = temp;
    }
}

void pop()
{
    int value;
    scanf("%d", &value);
    getchar();
    int index = hash(value);

    Node *curr = head[index];
    while (curr->next != NULL)
    {
        if (curr->value == value)
        {
            if (curr->prev == NULL)
            {
                head[index] = curr->next;
                if (curr->next != NULL)
                    curr->prev->next = NULL;
            }
            else
            {
                curr->prev->next = NULL;
                if (curr->next != NULL)
                {
                    curr->prev->next = NULL;
                    curr->next->prev = NULL;
                }
            }
            free(curr);
            return;
        }
        curr = curr->next;
    }
}