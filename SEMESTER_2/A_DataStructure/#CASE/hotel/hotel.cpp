#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define SIZE 100

struct Node
{
    char ID[225];
    char fname[225];
    char phnum[225];
    char room[225];

    int age;
    int nights;

    Node *next;
    Node *prev;
} *head[SIZE], *tail[SIZE];

Node *createNode(char *fname, char *phnum, char *room, int nights, int age)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    sprintf(temp->ID, "%c%c%.3d", toupper(room[0]), toupper(room[1]), rand() % 1000);
    strcpy(temp->fname, fname);
    strcpy(temp->phnum, phnum);
    temp->nights = nights;
    temp->age = age;
    temp->next = temp->prev = NULL;
    return temp;
}

int hashFunction(char *key)
{
    int sum = 0;
    for (int i = 2; key[i] != '\0'; i++)
    {
        sum += key[i];
    }
    return (sum - 1) % SIZE;
}

void push(char *fname, char *phnum, char *room, int nights, int age)
{
    Node *temp = createNode(fname, phnum, room, nights, age);
    int index = hashFunction(temp->ID);

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
    char ID[225];
    printf("Search with ID : ");
    scanf("%[^\n]", ID);
    getchar();

    int index = hashFunction(ID);
    Node *curr = head[index];
    while (curr != NULL)
    {
        if (strcmp(curr->ID, ID) == 0)
        {
            if (curr->prev == NULL)
            {
                head[index] = curr->next;
                if (curr->next != NULL)
                    curr->next->prev = NULL;
            }
            else
            {
                curr->prev->next = NULL;
                if (curr->next != NULL)
                {
                    curr->next->prev = curr->prev;
                }
            }
            free(curr);
            return;
        }

        curr = curr->next;
    }

    printf("NOT FOUND!\n");
}

int main()
{

    srand(time(NULL));

    return 0;
}