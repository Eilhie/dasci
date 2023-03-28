#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char key;
    Node *next;
} *head;

int sentenceChecker(char *sentence)
{
    char *token;

    token = strtok(sentence, " ");
    int count = 1;
    while (token != NULL)
    {
        token = strtok(NULL, " ");
        count++;
    }
    return count;
}

Node *createNode(char key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;

    newNode->next = NULL;
    return newNode;
}

void pushTail(char key)
{
    Node *temp = createNode(key);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
}

char popTail()
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    char res;
    if (head->next == NULL)
    {
        res = head->key;
        free(head);
        head = NULL;
        return res;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    res = temp->next->key;
    free(temp->next);
    temp->next = NULL;
    return res;
}

int continueRev()
{
    char input[225];
    int run = 1;
    do
    {
        printf("\n\nDo you want to continue [yes|no] ? ");
        scanf("%[^\n]", input);
        getchar();
        if (strcmp(input, "yes") == 0 || strcmp(input, "YES") == 0 || strcmp(input, "Yes") == 0)
            return 1;
        else if (strcmp(input, "no") == 0 || strcmp(input, "NO") == 0 || strcmp(input, "No") == 0)
            return 0;
        else
            run = 1;
    } while (run);

    return 0;
}

void reverseSentence(char *sentence)
{
    for (int i = 0; i < strlen(sentence); i++)
    {
        pushTail(sentence[i]);
    }
    for (int i = 0; i < strlen(sentence); i++)
    {
        printf("%c", popTail());
    }
    puts("");
}

int main()
{
    char *input;
    input = (char *)malloc(255 * sizeof(char));
    char *backup;
    backup = (char *)malloc(255 * sizeof(char));
    int resume;
    do
    {
        do
        {
            printf("Input Sentence [minimum 5 words]: ");
            scanf("%[^\n]", input);
            getchar();
            strcpy(backup, input);
        } while (sentenceChecker(input) < 5);
        printf("The result is: ");
        reverseSentence(backup);
        resume = continueRev();
    } while (resume);

    return 0;
}