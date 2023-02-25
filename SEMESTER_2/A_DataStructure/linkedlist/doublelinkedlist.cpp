#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Hero{
	char nama[100];
	int level;
	int hp;
	Hero *next;
	Hero *prev;
};
Hero *head, *tail = NULL;

Hero* createNewHero(char* nama, int level, int hp) {
	Hero* temp = (Hero*)malloc(sizeof(Hero));
	strcpy(temp->nama, nama);
	temp->level = level;
	temp->hp = hp;
	temp->next = temp->prev = NULL;
	return temp;
}

void pushHead(char* name, int level, int hp) {
	
	Hero* newHero = createNewHero(name, level, hp);
	if(!head) {
		head = newHero;
		tail = newHero;
	} else {
		newHero->next = head;
		head->prev = newHero;
		head = newHero;
	}
}

void pushTail(char* name, int level, int hp) {
	Hero* newHero = createNewHero(name, level, hp);
	if(!head) {
		head = tail = newHero;
		
	} else {
		newHero->prev = tail;
		tail->next = newHero;
		tail = newHero;
	}
}

void printList() {
	if(!head) {
		printf("No data inserted yet\n");
		getchar();
		return;
	}
	Hero* current = head;
	while (current) {
		printf("nama: %s\n", current->nama);
		printf("level: %d\n", current->level);
		printf("hp: %d\n", current->hp);
		puts("===============");
		current = current->next;
	}
}

void pushMid(char* name, int level, int hp) {
	if(head == NULL) {
		Hero* newHero = createNewHero(name, level, hp);
		head = tail = newHero;
		
	}
	else if(level < head->level){
		pushHead(name,level,hp);
	}
	else if(level > tail->level) {
		pushTail(name, level, hp);
	}
	else {
		Hero* newHero = createNewHero(name, level, hp);
		Hero* current = head;
		while(current->next != NULL && current->next->level < level) {
			current = current->next;
		}
		//hubungin kanan
		newHero->next = current->next;
		current->next->prev = newHero;
		//hubungin kiri
		current->next = newHero;
		newHero->prev = current;
	}
}

void popHead() {
	// check kosong , 1 data atau lebih dari satu data
	if(!head) return;
	
	if(head == tail) {
		free(head);
		head = tail = NULL;
	} else {
		Hero* toFree = head;
		head = head->next;
		free(toFree);
		toFree = NULL;
	}
}


void popTail() {
	if(head == NULL) return;
	
	if(head == tail) {
		free(head);
		head = tail = NULL;
	} else {
		Hero* current = head;
		while(current->next != tail) current = current->next;
		tail = current;
		
		free(current->next);
		current->next = NULL;
	}
	
}

void popMid(int level) {
	if (!head) {
		return;
	}
	else {
		if (head->level == level){
			popHead();
			
		}
		else if(tail->level == level) {
			popTail();
		}
		else{
			Hero* current = head;
			while(current) {
				if(current->level == level) {
					break;
				}
				current = current->next;
			}
			
			if(!current) {
				printf("level tidak ada.\n");
				return;
			}
			
			else {
				Hero *toDelete = current->next;
				current->prev->next = current->next;
				current->next->prev = current->prev;
				free(toDelete);
				return;
			}
			
		}
	}
}

void popAll() {
	while(head != NULL) popHead();
}


int main() {
//	char heroname[100];
//	scanf("%[^\n]", &heroname);
//	pushHead(heroname, 1, 200);
	pushHead("anjing", 3, 100);
	pushHead("bebe", 4, 3000);
	
	pushMid("anjing", 7, 100);
	pushMid("bebe", 4, 3000);
	pushMid("Hello", 6, 500);
	popMid(4);
//	popHead();
	printList();
	return 0;
}
