#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data
{
    char value[100];
    struct data *next;
};
struct data *hashTables[31];
int hash(const char *str)
{
    int length = strlen(str);
    int base = 11;
    int MOD = 31;
    int key = 0;
    for (int i = 0; i < length; i++)
    {
        key = (key * base) + (str[i] - 'a' + 1);
        key = key % MOD;
    }
    return (key * base) % MOD;
}

void chaining(int idx, const char *str)
{
    struct data *newData = (struct data *)malloc(sizeof(struct data));
    strcpy(newData->value, str);
    newData->next = NULL;
    if (!hashTables[idx])
        hashTables[idx] = newData;
    else
    {
        data *temp = hashTables[idx];
        while (temp && temp->next)
            temp = temp->next;
        temp->next = newData;
    }
}
void viewAll()
{
    // INSERT YOUR CODE HERE, View Data if the index have Data
    for (int i = 0; i < 31; i++)
    {
        if (hashTables[i] == NULL)
            continue;
        printf("Index %d : ", i);
        for (data *temp = hashTables[i]; temp != NULL; temp = temp->next)
        {
            printf("%s", temp->value);
            if (temp->next)
                printf(" -> ");
        }
        printf("\n");
    }
}
void popAll()
{
    // INSERT YOUR CODE HERE, Pop All the hashtable
    for (int i = 0; i < 31; i++)
    {
        if (hashTables[i] == NULL)
            continue;
        else
        {
            data *temp = hashTables[i]; // === head, head->next, hashtables = temp = head->next
            do
            {
                free(hashTables[i]);
                hashTables[i] = NULL;
                temp = temp->next;
                hashTables[i] = temp;
            } while (temp);
        }
    }
}
void init()
{
    for (int i = 0; i < 31; i++)
    {
        hashTables[i] = NULL;
    }
}
int main()
{
    char data[][100] =
        {
            "roti",
            "keju",
            "coklat",
            "durian",
            "nasi",
            "buncis",
            "ayam",
            "air",
            "mie",
            "tahu",
            "tempe",
            "susu",
            "sapi",
            "telur",
            "biskuit",
            "wortel",
            "steak",
            "kentang",
            "apel",
            "melon",
            "ikan"};

    init();

    int count = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < count; i++)
    {
        int idx = hash(data[i]);
        chaining(idx, data[i]);
    }

    viewAll();
    popAll();
    viewAll();
    return 0;
}