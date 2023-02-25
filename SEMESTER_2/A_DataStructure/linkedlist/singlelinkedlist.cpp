#include <stdio.h>
#include <stdlib.h>

struct Node{
	// isinya data
	int data;
	
	Node *next;
	
};

Node *head = NULL;
Node *tail = NULL;

// function to allocate memory
Node* createNode(int data) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// push head -> insert ke kepala
void pushHead(int data) {
	
	Node *newNode = createNode(data);
	if(head == NULL) {
		head = newNode;
		tail = newNode;
	} else {
		newNode->next = head;
		head = newNode;
	}
}


void printList() {
	
	while (head != NULL) {
		printf("%d ->", head->data);
		head = head->next;
	}
	puts("");
}

int main() {
	pushHead(10);
	pushHead(20);
	pushHead(30);
	
	printList();
	return 0;
}
