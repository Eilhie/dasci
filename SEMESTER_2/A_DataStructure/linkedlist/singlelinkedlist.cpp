// #include <stdio.h>
// #include <stdlib.h>

// struct Node{
// 	// isinya data
// 	int data;
	
// 	Node *next;
	
// };

// Node *head = NULL;
// Node *tail = NULL;

// // function to allocate memory
// Node* createNode(int data) {
// 	Node *newNode = (Node*) malloc(sizeof(Node));
// 	newNode->data = data;
// 	newNode->next = NULL;
// 	return newNode;
// }

// // push head -> insert ke kepala
// void pushHead(int data) {
	
// 	Node *newNode = createNode(data);
// 	if(head == NULL) {
// 		head = newNode;
// 		tail = newNode;
// 	} else {
// 		newNode->next = head;
// 		head = newNode;
// 	}
// }


// void printList() {
	
// 	while (head != NULL) {
// 		printf("%d ->", head->data);
// 		head = head->next;
// 	}
// 	puts("");
// }

// int main() {
// 	pushHead(10);
// 	pushHead(20);
// 	pushHead(30);
	
// 	printList();
// 	return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
	int price;
	Book *next;
} *head, *tail;


Book* createNode(int price) {
	Book *temp = (Book*)malloc(sizeof(Book));
	temp->price = price;
	
	temp->next = NULL;

	return temp;
}

void pushHead(int price) {
	Book *node = createNode(price);

	if(head == NULL){
		head = tail = node;
	} else {
		node->next = head;
		head = node;
	}
}

void printLL(){
	Book* curr = head;
	while(curr != NULL){
		printf("%d\n", curr->price);
		curr = curr->next;
	}
}

int main(){
	pushHead(100);
	pushHead(500);
	pushHead(750);
	
	printLL();
	return 0;
}