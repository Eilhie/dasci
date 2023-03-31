#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

struct node
{
	char name[30];
	int age;
	char phone[20];
	char rclass[10];
	int stay;
	char bookid[10];

	node *next;
} *head[SIZE];

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

node *createnew(char iname[], int iage, char phone[], char rclass[], int istay)
{
	node *temp = (node *)malloc(sizeof(node));
	sprintf(temp->bookid, "%c%d%.3d", toupper(rclass[0]), toupper(rclass[1]), rand() % 1000);
	strcpy(temp->name, iname);
	temp->age = iage;
	strcpy(temp->phone, phone);
	strcpy(temp->rclass, rclass);
	temp->stay = istay;

	return temp;
}

void push(char iname[], int iage, char phone[], char rclass[], int istay)
{
	node *insert = createnew(iname, iage, phone, rclass, istay);
	int key = hash(insert->bookid);

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
		node *temp = head[key];
		head[key] = head[key]->next;
		free(temp);
		printf("Booking ID '%s' successfully deleted\n", bookid);
	}
	else
	{
		node *curr = head[key];
		while (curr->next != NULL && strcmp(curr->next->bookid, bookid) != 0)
		{
			curr = curr->next;
		}

		if (curr->next == NULL)
		{
			printf("Booking ID '%s' not found\n", bookid);
		}
		else
		{
			node *temp = curr->next;
			curr->next = temp->next;
			temp->next = NULL;
			printf("Booking ID '%s' successfully deleted\n", temp->bookid);
			free(temp);
		}
	}
}

void printbook()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (head[i] != NULL)
		{
			node *curr = head[i];
			while (curr->next != NULL)
			{
				printf("Booking ID    : %s\n", curr->bookid);
				printf("Name          : %s\n", curr->name);
				printf("Phone Number  : %s\n", curr->phone);
				printf("Room Class    : %s\n", curr->rclass);
				printf("Stay Duration : %d\n", curr->stay);
			}
		}
	}
}

int phoneValidation(char telp[])
{
	int len = strlen(telp);
	char number[] = "+62";
	int startlen = strlen(number);

	if (strncmp(telp, number, 3) != 0)
		return false;

	int space = 0;
	for (int i = 0; i < len; i++)
	{
		if (telp[i] == ' ')
			space++;
	}

	if (space >= 1 && (len - startlen - space) == 11)
		return true;
	else
		return false;
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
			char phone;
			char rclass;
			int istay;

			printf("Name: ");
			scanf("%[^\n]", iname);
			getchar();
			printf("Age [Min: 18]: ");
			scanf("%d", iage);
			getchar();

			if (iage >= 18)
			{
				printf("Phone: ");
				scanf("%[^\n]", phone);
				getchar();

				int validphone = phoneValidation(phone);

				if (validphone == true)
				{
					printf("Rooms\n");
					printf("----------------------------------------\n");
					printf("1: Regular\n");
					printf("2: Deluxe\n");
					printf("3: Suite\n");
					printf("----------------------------------------\n");
					printf("Room Type: ");
					scanf("%[^\n]", rclass);
					getchar();
					printf("Stay Duration: ");
					scanf("%d", istay);
					getchar();
					puts("");

					if (strcmp(rclass, "Regular") == 0)
					{
						printf("Room Class : Regular\n");
					}
					else if (strcmp(rclass, "Deluxe") == 0)
					{
						printf("Room Class : Deluxe\n");
					}
					else if (strcmp(rclass, "Suite") == 0)
					{
						printf("Room Class : Suite\n");
					}

					push(iname, iage, phone, rclass, istay);
				}
			}
		}
		else if (hinput == 2)
		{
			printbook();
			active = 0;
		}
		else if (hinput == 3)
		{
			char bookid[10];
			scanf("%[^\n]", bookid);
			pop(bookid);
		}
		puts("");
		printf("Continue?");
		printf("Yes > Input any non-zero number\n");
		printf("No  > Input 0\n");
		scanf("%d", active);
	}

	return 0;
}
