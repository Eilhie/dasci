#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[100];
    int age;
    char role[100];
    int level;

    node *next;
    node *prev;
} *head = NULL, *tail = NULL;

node *createNode(char name[], int age, char role[])
{
    node *newNode = (node *)malloc(sizeof(node));

    strcpy(newNode->name, name);
    newNode->age = age;
    strcpy(newNode->role, role);

    if (strcmp(newNode->role, "VVIP") == 0)
    {
        newNode->level = 3;
    }
    else if (strcmp(newNode->role, "VIP") == 0)
    {
        newNode->level = 2;
    }
    else
    {
        newNode->level = 1;
    }

    newNode->next = newNode->prev = NULL;

    return newNode;
}

void insertq(char name[], int age, char role[])
{
    node *toPush = createNode(name, age, role);
    // Belum punya data
    if (!head)
    {
        head = tail = toPush;
    }
    else
    {
        if (head->level < toPush->level)
        {
            // PushHead
            toPush->next = head;
            head->prev = toPush;
            head = toPush;
        }
        else if (tail->level >= toPush->level)
        {
            // PushTail
            tail->next = toPush;
            toPush->prev = tail;
            tail = toPush;
        }
        else
        {
            // PushMid
            node *curr = head;
            while (curr && curr->level >= toPush->level)
            {
                curr = curr->next;
            }
            toPush->next = curr;
            toPush->prev = curr->prev;
            curr->prev = toPush;
            toPush->prev->next = toPush;
        }
    }
}

void addqueue()
{
    char name[100], role[100];
    int age;
    printf("Input Name: ");
    scanf("%[^\n]", name);
    getchar();
    printf("Input Age: ");
    scanf("%d", &age);
    getchar();
    printf("Input Role: ");
    scanf("%[^\n]", role);
    getchar();

    insertq(name, age, role);
    printf("Guest %s with %s Role coming to queue\n", name, role);
    printf("Press any key to continue...\n");
    getchar();
}

void viewq()
{
    if (!head)
    {
        printf("Nothing in queue\nPress any key to continue...\n");
        getchar();
    }
    else
    {
        node *curr = head;
        while (curr != NULL)
        {
            printf("%s %d %s", curr->name, curr->age, curr->role);
            curr = curr->next;
        }
        printf("\n\nPress any key to continue...\n");
        getchar();
    }
}

void pophead()
{
    // Kalau cuman 1 data
    if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
}

void dequeue1()
{
    if (!head)
    {
        printf("Nothing in queue\nPress any key to continue...\n");
        getchar();
    }
    else
    {
        printf("Guest %s with %s Role is served.\n", head->name, head->role);
        pophead();
        printf("Press any key to continue...\n");
        getchar();
    }
}

void dequeueAll()
{
    if (!head)
    {
        printf("Nothing in queue\nPress any key to continue...\n");
        getchar();
    }
    else
    {
        while (head != NULL)
        {
            printf("Guest %s with %s Role is served.\n", head->name, head->role);
            pophead();
        }
        printf("Press any key to continue...\n");
        getchar();
    }
}

void dismissAll()
{
    if (!head)
    {
        printf("Nothing in queue\nPress any key to continue...\n");
        getchar();
    }
    else
    {
        while (head != NULL)
        {
            //      printf("Guest %s with %s Role is served.\n", head->name, head->role);
            pophead();
        }
        printf("Queue dismissed.\n");
        printf("Press any key to continue...\n");
        getchar();
    }
}

void menu()
{
    int selection;
    do
    {
        system("cls");
        printf("Welcome...\n1. Add Queue\n2. Serve One\n3. Serve All\n4. View Queue\n5. Dismiss All\n6. Exit\n>> ");
        scanf("%d", &selection);
        getchar();

        switch (selection)
        {
        case 1:
        {
            addqueue();
            break;
        }
        case 2:
        {
            dequeue1();
            break;
        }
        case 3:
        {
            dequeueAll();
            break;
        }
        case 4:
        {
            viewq();
            break;
        }
        case 5:
        {
            dismissAll();
            break;
        }
        case 6:
        {
            printf("bye.\n");
            break;
        }
        }
    } while (selection != 6);
}

int main()
{
    menu();
    return 0;
}