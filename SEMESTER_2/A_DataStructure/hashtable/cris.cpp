#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define size 10

struct node
{
	char name[201];
	int nim;
	node *next;
} *head[size];

int hash(int nim)
{
	int key = nim % size;
	
	return key;
}

node *createnew(char name[], int nim)
{
	node *newnode = (node*)malloc(sizeof(node));
	strcpy(newnode->name, name);
	newnode->nim = nim;
	newnode->next = NULL;
	
	return newnode;
}

void push(char name[], int nim)
{
	node *insert = createnew(name, nim);
	int key = hash(nim);
	
	if(head[key] == NULL)
	{
		head[key] = insert;
	}
	else
	{
		node *curr = head[key];
		
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = insert;
	}
}

void pop(int nim)
{
	int key = hash(nim);
	
	if(head[key] == NULL)
	{
		printf("Data [%d] not found\n", nim);
		return;
	}
	else if(head[key]->nim == nim)
	{
		node *temp = head[key];
		head[key] = head[key]->next;
		free(temp);
		printf("Data [%d] successfully deleted\n", nim);
	}
	else
	{
		node *curr = head[key];
		
		while(curr->next != NULL && curr->nim != nim)
		{
			curr = curr->next;
		}
		
		if(curr->next == NULL)
		{
			printf("Data [%d] not found\n", nim);
			return;
		}
		else
		{
			node *temp = curr->next;
			curr->next = temp->next;
			temp->next = NULL;
			free(temp);
			
			printf("Data [%d] successfully deleted\n", nim);
		}
	}
}

void search(int nim)
{
	int key = hash(nim);
	
	if(head[key] == NULL)
	{
		printf("Data [%d] not found\n", nim);
		return;
	}
	else if(head[key]->nim == nim)
	{
		printf("Data [%d] found\n", nim);
	}
	else
	{
		node *curr = head[key];
		
		while(curr->next != NULL && curr->nim != nim)
		{
			curr = curr->next;
		}
		
		if(curr->next == NULL)
		{
			printf("Data [%d] not found\n", nim);
			return;
		}
		else
		{
			printf("Data [%d] found\n", nim);
		}
	}
}

void printall()
{
	for(int i = 0; i < size; i++)
	{
		printf("Row %d:", i+1);
		
		node *curr = head[i];
		
		while(curr != NULL)
		{
			printf(" [%s | %d]", curr->name, curr->nim);
            curr = curr->next;
		}
        puts(" [NULL]");
	}
}

int main()
{
	push("Chris", 13);
	push("Alden", 10);
	push("Marvin", 17);
	push("Kenneth", 15);
	
	printall();
	
	return 0;
}
