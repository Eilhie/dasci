#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct node
{
    char name[30];
    int rclass;
    char bookid[10];

    node *next;
} *head[SIZE];

void booking(int rclass)
{
    char bookid[10];
    if (rclass == 1)
    {
        strcpy(bookid[0], "R");
        strcpy(bookid[1], "E");
    }
    else if (rclass == 2)
    {
        strcpy(bookid[0], "D");
        strcpy(bookid[1], "E");
    }
    else if (rclass == 3)
    {
        strcpy(bookid[0], "S");
        strcpy(bookid[1], "U");
    }

    for (int i = 2; i < 5; i++)
    {
        strcpy(bookid[i], (char)rand() % 10);
    }

    return bookid;
}

int hash(char bookid[])
{
    int x = 0;
    for (int i = 2; i < 5; i++)
    {
        x += bookid[i];
    }
    x = x - 1;

    int key = x % SIZE;

    return key;
}

node *createnew(char name[], int rclass, char bookid[])
{
    node *newnode = (node *)malloc(sizeof(node));
    strcpy(newnode->name, name);
    newnode->rclass = rclass;
    strcpy(newnode->bookid, bookid);
    newnode->next = NULL;

    return newnode;
}

void push(char name[], int rclass, char bookid[])
{
    node *insert = createnew(name, rclass, bookid);
    int key = hash(bookid);

    if (head[key] == NULL)
    {
        head[key] = insert;
    }
    else
    {
        node *curr = head[key];
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = insert;
    }
}

void pop(char bookid[])
{
    int key = hash(bookid);

    if (head[key] == NULL)
    {
        printf("Booking ID '%s' not found\n", bookid);
        return;
    }

    if (strcmp(head[key]->bookid, bookid) == 0)
    {
    }
}

void printall()
{
}

void search(char bookid[])
{
}

int main()
{
    int active = 1;

    while (active != 0)
    {
        printf("Hotel Gransylvania\n");
        printf("----------------------------------------\n");
        printf("1. Booking Hotel\n");
        printf("2. View Bookings\n");
        printf("3. Delete Bookings\n");
        printf("----------------------------------------\n");
        printf("Input: ");
        int hinput;
        scanf("%d", hinput);

        if (hinput == 1)
        {
            char iname[30];
            int iage;
            int phone;
            int rclass;
            int istay;

            printf("Name: ");
            scanf("%[^\n]", iname);
            getchar();
            printf("Age [Min: 18]: ");
            scanf("%d", iage);
            getchar();
            printf("Phone: ");
            scanf("%d", phone);
            getchar();
            printf("Rooms\n");
            printf("----------------------------------------\n");
            printf("1 > Regular\n");
            printf("2 > Deluxe\n");
            printf("3 > Suite\n");
            printf("----------------------------------------\n");
            printf("Room Type: ");
            scanf("%d", rclass);
            getchar();
            printf("Stay Duration: ");
            scanf("%d", istay);
            getchar();
            puts("");

            bookid = booking(rclass);
            printf("Name       : %s\n", iname);
            printf("Age        : %d\n", iage);
            printf("Phone      : %d\n", phone);

            if (rclass == 1)
            {
                printf("Room Class : Regular\n");
            }
            else if (rclass == 2)
            {
                printf("Room Class : Deluxe\n");
            }
            else if (rclass == 3)
            {
                printf("Room Class : Suite\n");
            }

            printf("Stay Duration : %d\n", istay);
            printf("Booking ID    : %s\n", bookid);

            push(iname, rclass, bookid);
        }
        else if (hinput == 2)
        {
            printall();
        }
        else if (hinput == 3)
        {
            del(iname);

            int update;
            printf("Print Updated Booking List?\n");
            printf("Yes > Input 1 or higher\n");
            printf("No  > Input 0 or lower\n");
            scanf("%d", update);

            if (update >= 1)
            {
                printall();
            }
        }
        puts("");
        printf("Continue?")
            printf("Yes > Input any non-zero number\n");
        printf("No  > Input 0\n");
        scanf("%d", active);
    }

    return 0;
}
TheLab.cpp 4 KB