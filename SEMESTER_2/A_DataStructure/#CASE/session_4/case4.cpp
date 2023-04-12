#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1007

int last = 1;

struct Node
{
    char ID[255];
    char title[225];
    char author[225];
    char ISBN[225];
    int pnum;

    Node *next;
    Node *prev;
} *head[SIZE], *tail[SIZE];

Node *createNode(char *title, char *author, char *ISBN, int pnum)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->author, author);
    strcpy(temp->ISBN, ISBN);
    strcpy(temp->title, title);
    temp->pnum = pnum;

    sprintf(temp->ID, "B%.5d-%s-%c%c", last, ISBN, toupper(author[0]), toupper(title[0]));

    temp->next = temp->prev = NULL;

    last++;

    return temp;
}

int hash(char *key)
{
    int sum = 0;
    for (int i = 0; i < strlen(key); i++)
    {
        sum += key[i];
    }
    return sum % SIZE;
}

int isalldigit(char *ISBN)
{
    for (int i = 0; i < strlen(ISBN); i++)
    {
        if (!isdigit(ISBN[i]))
            return 0;
    }
    return 1;
}

int isunique(char *title)
{
    for (int i = 0; i < SIZE; i++)
    {
        Node *curr = head[i];
        while (curr != NULL)
        {
            if (strcmp(curr->title, title) == 0)
            {
                printf("The book title yet exist!\n");
                return 0;
            }
            curr = curr->next;
        }
    }
    return 1;
}

void insert()
{

    char title[225], author[225], ISBN[225];
    int pnum;

    bool error = true;

    while (error)
    {
        printf("Title : ");
        scanf("%[^\n]", title);
        getchar();

        if (strlen(title) >= 5 && strlen(title) <= 50 && isunique(title))
            error = false;
    }

    error = true;

    while (error)
    {
        printf("Author : ");
        scanf("%[^\n]", author);
        getchar();

        if ((strlen(author) >= 3 && strlen(author) <= 25) && (strncmp(author, "Mr.", 3) == 0 || strncmp(author, "Mrs.", 4) == 0))
            error = false;
    }

    error = true;

    while (error)
    {
        printf("ISBN : ");
        scanf("%[^\n]", ISBN);
        getchar();

        if (strlen(ISBN) >= 10 && strlen(ISBN) <= 13 && isalldigit(ISBN))
            error = false;
    }

    error = true;

    while (error)
    {
        printf("Page : ");
        scanf("%d", &pnum);
        getchar();

        if (pnum >= 16)
            error = false;
    }

    Node *temp = createNode(title, author, ISBN, pnum);

    int index = hash(temp->ID);
    if (head[index] == NULL)
        head[index] = tail[index] = temp;
    else
    {
        tail[index]->next = temp;
        temp->prev = tail[index];
        tail[index] = temp;
    }
}

void view()
{
    puts("-------------------------------------------------------------------------------------------------------------------------------------------");
    printf("| Book ID                 | Book Title                                         | Book Author               | ISBN           | Page Number |\n");
    puts("-------------------------------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < SIZE; i++)
    {
        Node *curr = head[i];
        while (curr != NULL)
        {
            printf("| %-19s | %-50s | %-25s | %-14s | %-11d |\n", curr->ID, curr->title, curr->author, curr->ISBN, curr->pnum);
            puts("-------------------------------------------------------------------------------------------------------------------------------------------");
            curr = curr->next;
        }
    }
}

void deleteBook()
{
    char ID[225];

    printf("Input Book ID to delete : ");
    scanf("%[^\n]", ID);
    getchar();

    Node *curr = head[hash(ID)];
    while (curr != NULL)
    {
        if (strcmp(curr->ID, ID) == 0)
        {
            printf("ID : %s\nTitle : %s\nAuthor : %s\nISBN : %s\nPage Num : %d\n", curr->ID, curr->title, curr->author, curr->ISBN, curr->pnum);

            bool del = true;
            char conf;
            while (del)
            {
                printf("Are you sure[y/n]? ");
                scanf("%c", &conf);
                getchar();
                if (conf == 'y')
                    del = false;
            }
            if (curr->prev == NULL)
            {
                head[hash(ID)] = curr->next;
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

    printf("Book not found!\n");
}

int main()
{
    int run = 1, input;
    do
    {
        do
        {
            printf("BLUEJACK LIBRARY\n");
            printf("=================\n");
            printf("1. View\n");
            printf("2. Insert\n");
            printf("3. Delete\n");
            printf("4. Exit\n");
            printf(">>");
            scanf("%d", &input);
            getchar();
        } while (input > 4 || input < 0);
        switch (input)
        {
        case 1:
            view();
            break;
        case 2:
            insert();
            break;
        case 3:
            deleteBook();
            break;
        case 4:
            run = 0;
            break;
        }
    } while (run);
    return 0;
}