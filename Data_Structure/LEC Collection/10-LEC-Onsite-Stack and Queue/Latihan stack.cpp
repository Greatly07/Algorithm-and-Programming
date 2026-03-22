#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FULL 10

struct Data
{
	char k;
	struct Data *next;
}*head, *tail, *curr;

int size();
int is_empty();
int is_full(); 
void display_all();
void menu1();

struct Data *newNode(char);
void pushHead(char);
void popHead();
void popAll();
char peek();


int main()
{
	int pilih;
	do
	{
		printf("size() : %d\nis_empty() : %d\nis_full() : %d\n\n", size(), is_empty(), is_full());
		display_all();
		printf("\n\n1. Input Kata, push char ke stack [max 10 char]\n2. PopStack\n3. Peek / Top\n0. Exit, PopAll\nPilih : ");
		scanf("%d", &pilih);
		switch(pilih)
		{
			case 1:
				menu1();
				break;
			case 2:
				popHead();
				break;
			case 3:
				printf("%c", peek());
				break;
			default:
				printf("not a choice!\n");
				break;
		}
	} while(pilih != 0);
	return 0;
}

void display_all()
{
	curr = head;
	while(curr)
	{
		printf("%c ", curr->k);
		curr = curr->next;
	}
}

void menu1()
{
	char word[10 + 1];
	
	printf("Masukkan kata : ");
	scanf(" %[^\n]", &word);
	if(size() + strlen(word) > FULL)
	{
		printf("jika diinsert FULL!\n");
		getchar();
		return;
	}
	else
	{
		int n = strlen(word);
		for(int i = 0; i < n; i++)
		{
			pushHead(word[i]);
		}
	}
}

struct Data *newNode(char k)
{
	curr = (struct Data *)malloc(sizeof(struct Data));
	curr->k = k;
	curr->next = NULL;
	
	return curr;
}

void pushHead(char k)
{
	curr = newNode(k);
	if(head == NULL)
	{
		head = tail = curr;
	}
	else
	{
		curr->next = head;
		head = curr;
	}
}

void popHead()
{
	curr = head;

	if(head == tail) // last data
	{
		head = tail = NULL;
	}
	else // not the last data
	{
		head = head->next;
	}

	free(curr);
}

void popAll()
{
	while(head)
	{
		popHead();
	}
}

char peek()
{
	if(head)
		return head->k;
	else return -1;
}

int size()
{
	curr = head;
	int n = 0;
	while(curr)
	{
		n++;
		curr = curr->next;
	}
	return n;
}

int is_empty()
{
	if(head)
	{
		return 0;
	}
	return 1;
}

int is_full()
{
	if(size() >= FULL)
	{
		return 1;
	}
	return 0;
}
