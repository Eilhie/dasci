#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char name[225];
    int age;
    char description[225];
    int prior;

    Node* next;
} *head, *tail;


Node* createNode(char* name, int age, char* description, int prior){
    Node* temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->name, name);
    temp->age = age;
    strcpy(temp->description, description);
    temp->prior = prior;

    temp->next = NULL;

    return temp;
}

void pushTail(char* name, int age, char* description, int prior){
    Node* temp = createNode(name, age, description, prior);
    if(head == NULL){
        head == tail == NULL;
        head = temp;
        return;
    } 
    if(head->prior < prior){
        temp->next = head;
        head = temp;
    } else {
        Node* curr = head;
        while(curr->next != NULL && curr->next->prior > prior){
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void insert(){
    char name[30], description[100], code[30];
    int age, prior;
    do{
        printf("Input patient name[4-25]:");
        scanf("%[^\n]", name); getchar();
    }while(strlen(name) < 4 || strlen(name) > 25);
    do
    {
        printf("Input patient age[>= 0]:");
        scanf("%d", &age); getchar();
    } while (age < 0);
    do{
        printf("Input patient description[>= 6]:");
        scanf("%[^\n]", description); getchar();
    }while(strlen(description) < 6);
    do{
        printf("Input code[Red|Yellow|Green]:");
        scanf("%s", code); getchar();
    }while(strcmp(code, "Red") != 0 && strcmp(code, "Yellow") != 0 && strcmp(code, "Green") != 0);
    if(strcmp(code, "Red") == 0) prior = 3;
    else if(strcmp(code, "Yellow") == 0 ) prior = 2;
    else prior = 3;

    pushTail(name, age, description, prior);
}

void view(){
    if(head == NULL){
        printf("There is no queue yet !\n\n");
        printf("press Enter to continue . . .");
        getchar();
    } else {
        puts("Patient List:");
        Node* curr = head;
        int i = 1;
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("|No  | Name                      | Age  | Description                                             | Code    |\n");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        while(curr != NULL){
            printf("|%-4d| %-26s| %-5d| %-56s| ", i, curr->name, curr->age, curr->description);
            if(curr->prior == 3) printf("%-8s|\n", "Red");
            else if(curr->prior == 2) printf("%-8s|\n", "Yellow");
            else printf("%-8s|\n", "Green");
            curr = curr->next;
            i++;
        }
        printf("-------------------------------------------------------------------------------------------------------------\n");
    }
}

void nextQ(){
    if(head == NULL){
        printf("There is no queue yet !\n\n");
    } else {
        printf("The next patient is:\n");
        printf("Name           : %s\n", head->name);
        printf("Age            : %d\n", head->age);
        printf("Description    : %s\n", head->description);
        printf("Code           : ");
        if(head->prior == 3) printf("%s\n", "Red");
        else if(head->prior == 2) printf("%s\n", "Yellow");
        else printf("%s\n", "Green");

        Node* temp = head;
        head = head->next;
        free(temp);
    }
    printf("press Enter to continue . . .");
    getchar();
}

int main(){
    int run = 1, input;
    do{
        do{
            printf("BLUEJACK HOSPITAL\n");
            printf("=================\n");
            printf("1. Insert\n");
            printf("2. View\n");
            printf("3. Next Queue\n");
            printf("4. Exit\n");
            printf(">>");
            scanf("%d", &input); getchar();
        } while (input > 4 || input < 0);
        switch (input){
            case 1:
                insert();
                break;
            case 2:
                view();
                break;
            case 3:
                nextQ();
                break;
            case 4:
                run = 0;
                break;
        }
    }while(run);
    
    return 0;
}