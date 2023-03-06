#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    // data
    char* cakecode;
    char* cakename;
    int available;
    int price;

    // next
    Node *next;
} *head = NULL, *tail = NULL;

Node* createNode(const char* cakecode, const char* cakename, int available, int price){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->cakecode = (char*) malloc(strlen(cakecode) + 1);
    temp->cakename = (char*) malloc(strlen(cakename) + 1);
    strcpy(temp->cakecode, cakecode);
    strcpy(temp->cakename, cakename);
    temp->available = available;
    temp->price = price;
    temp->next = NULL;

    return temp;
}

void insert(const char* cakecode, const char* cakename, int available, int price){

    Node *temp = createNode(cakecode, cakename, available, price);

    if (head == NULL) {
        head = temp;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

void printlist(){
    Node *current = head;
    int i = 1;

    printf("No. | Cake Code | Cake Name            | Available | Price\n");
    printf("---------------------------------------------------------------\n");

    while(current != NULL){
        printf("%d. | %s     | %s\t|        %d | Rp. %d,-\n", i, current->cakecode, current->cakename, current->available, current->price);
        current = current->next;
        i++;
    }
    puts("---------------------------------------------------------------\n\n");
}

struct Node* search_node(const char* search_data) {
    Node* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->cakecode, search_data) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

int sellNaddStock(const char* cakecode, int input){
    Node *node = search_node(cakecode);
    if (node == NULL) {
        printf("\n--- The Cake Code doesn't exist ---\n");
        return 1;
    }
    while (head != NULL) {
        if(strcmp(cakecode, head->cakecode) == 0){
            int quantity;
            if(input == 1){
                printf("Input Quantity [0..%d]: ", head->available);
                do {
                    scanf("%d", &quantity); getchar();
                } while (quantity < 0 || quantity > head->available);
                head->available -= quantity;

                printf("Total Price is : Rp %d,- x %d = Rp %d,-\n\n", head->price, quantity, head->price * quantity);

            }   
            else if(input == 2){
                printf("Input Quantity [0..10]: ", head->available);
                do {
                    scanf("%d", &quantity); getchar();
                } while (quantity < 0 || quantity > 10);
                head->available += quantity;
                puts("--- Adding Stock Success ---");
            }
            
            
            printf("--- Thank You ---\n");
            return 0;
        }
    }
}

int main(){
    insert("CK001", "Blueberry Cake", 13, 25000);
    insert("CK009", "Chocochip Cake", 5, 20000);
    insert("CK017", "Mayonaise Cake", 24, 30000);
    insert("CK023", "Strawberry Shortcake", 7, 17500);

    int run = 1;
    char cakecode[7];
    int flow;

    do {
        printf("BLUE CAKE SHOP CASHIER\n");
        printf("======================");

        printlist();

        int input;
        do{
            printf("Menu:\n");
            printf("1. Sell\n");
            printf("2. Add Stock\n");
            printf("3. Exit\n");
            printf("Input choice: ");
            scanf("%d", &input); getchar();

            switch (input) {
            case 1:
                flow = 1;
                while(flow){
                    printf("Input Cake Code [5 chars]: ");
                    scanf("%s", cakecode);
                    flow = sellNaddStock(cakecode, input);
                }
                break;
            case 2:
                flow = 1;
                while(flow){
                    printf("Input Cake Code [5 chars]: ");
                    scanf("%s", cakecode);
                    flow = sellNaddStock(cakecode, input);
                }
                break;
            case 3:
                exit(0);
                break;
            }
        } while(input < 1 || input > 3);

    } while (run);

    return 0;
}

