#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int index, gold;
    int depth;
    Node *left, *right;
} *root = NULL;

Node *createNode(int index, int gold, int depth)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->index = index;
    temp->gold = gold;
    temp->depth = depth;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *root, int index, int gold, int depth)
{
    if (!root)
        return createNode(index, gold, depth);
    if (root->index > index)
        root->left = insert(root->left, index, gold, depth + 1);
    if (root->index < index)
        root->right = insert(root->right, index, gold, depth + 1);
    return root;
}

int search(Node *root, int index, int gold)
{
    if (!root)
    {
        return 0;
    }
    if (root->index == index)
    {
        root->gold += gold;
        return root->gold;
    }
    else if (root->index > index)
        search(root->left, index, gold);
    else if (root->index < index)
        search(root->right, index, gold);
}

void insert1()
{
    int index, gold = 0;
    do
    {
        printf("Input cave index[1-999] : ");
        scanf("%d", &index);
        getchar();
    } while (index < 1 || index > 999);
    do
    {
        printf("Input gold production[1-100] : ");
        scanf("%d", &gold);
        getchar();
    } while (gold < 1 || gold > 100);
    int hasil = search(root, index, gold);
    if (hasil == 0)
    {
        printf("New cave index detected\nTotal gold for cave %d is %d", index, gold);
        puts("\n");
        root = insert(root, index, gold, 1);
    }
    else
    {
        printf("Cave index already exists\nNew total gold production for cave %d is %d", index, hasil);
        puts("\n");
    }
}

void print(Node *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        print(root->left);
        printf("Cave %d(depth %d),total gold production: %d\n", root->index, root->depth, root->gold);
        print(root->right);
    }
}

void total_level(Node *root, int index, int *sum)
{
    if (!root)
        return;
    if (index == 1)
        *sum += root->gold;
    if (index > 1)
    {
        total_level(root->left, index - 1, sum);
        total_level(root->right, index - 1, sum);
    }
}

int depth(Node *root)
{
    if (!root)
        return 0;
    else
    {
        int left = depth(root->left);
        int right = depth(root->right);
        if (left >= right)
            return left + 1;
        else
            return right + 1;
    }
}

void display_report(Node *root)
{
    int sum = 0;
    for (int i = 0; i < depth(root); i++)
    {
        total_level(root, i + 1, &sum);
        printf("Total gold production for depth %d is %d\n", i + 1, sum);
        sum = 0;
    }
}

int main()
{
    printf("Hov Mining Simulator\n");
    int choose;
menu:
    do
    {
        printf("[1] Insert Mining Data\n[2] Display All Data\n[3] Display Mining Reports\n[4] Exit\nInput : ");
        scanf("%d", &choose);
        getchar();
    } while (choose < 1 || choose > 4 || !choose);
    switch (choose)
    {
    case 1:
    {
        insert1();
        goto menu;
        break;
    }
    case 2:
    {
        if (!root)
            printf("Cave data is empty, nothing to display.");
        puts("\n");
        print(root);
        goto menu;
        break;
    }
    case 3:
    {
        if (!root)
            printf("Cave data is empty, nothing to display.\n");
        puts("\n");
        display_report(root);
        goto menu;
        break;
    }
    case 4:
    {
        root = NULL;
        printf("All data has been removed from memory\nThank you for playing, see you again...\n");
        break;
    }
    }
}