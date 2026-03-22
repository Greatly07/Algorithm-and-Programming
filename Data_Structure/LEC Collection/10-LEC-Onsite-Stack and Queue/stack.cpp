#include <stdio.h> // i/o
#include <stdlib.h> // malloc, system
#include <string.h> // strlen & string function
#define FULL 10

struct Data
{
	char k;
	struct Data * next;
}*head, *tail, *curr;

void displayAll();
void pushHead(char k);
void popHead();
void popAll();
char peek(); // top(); return top data / last pushed data if exist, else return -1
int size(); // numNodes in stack lists  
int is_empty(); // return 1 if size() == 0, else return 0
int is_full(); // return 1 if size() == FULL, else return 0
void displayInfoAndData();
void menu();
void menu1(); //pushHead

int main()
{
	int pilih;
	do
	{
		system("cls");
		displayInfoAndData();
		menu();
	
		scanf("%d", &pilih); getchar();
		switch(pilih)
		{
		case 1 : menu1(); break;
		case 2 : popHead(); break;
		case 3 : printf("\npeekChar() : '%c'\n", peek()); getchar(); break;
		}
	} while (pilih != 0);
	popAll();
	return 0;
}

void menu1()
{
	int i;
	char kata[100]={0};
	
	printf("Masukkan kata : ");
	gets(kata);  
	if(strlen(kata) + size() <= FULL)
	{
		for(i=0; i<strlen(kata); i++)
		{
		 pushHead(kata[i]);
		} 
	}
	else
	{
		printf("jika diinsert FULL!"); 
		getchar();
	}
}

void displayInfoAndData()
{
		printf("Stack\n");
		printf("=====\n\n");
		printf("size() : %d\n", size());
		printf("is_empty() : %d\n", is_empty());
		printf("is_full() : %d\n", is_full());
		puts("");
		displayAll();
}

void menu()
{
	printf("\n\n");
	printf("1. Input Kata, push char ke stack [max 10 kar]\n");
	printf("2. PopStack\n");
	printf("3. Peek / Top\n");
	printf("0. Exit, PopAll\n");
	printf("Pilih : ");
}

int is_full()
{
	if(size() == FULL)
		return 1;
	else 
		return 0;
}

int is_empty()
{
	if(head == NULL)
		return 1;
	else return 0;
}


int size()
{
	int n=0;
	curr = head;
	while(curr)
	{
		curr = curr->next;
		n++;
	}
	return n;
}

char peek()
{
	if(head)
		return head->k;
	else return -1;
}

void popAll()
{
	while(head)
	{
		popHead();
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

struct Data *newNode(char k)
{
	curr = (struct Data *) malloc(sizeof(struct Data));
	curr->k = k;
	curr->next = NULL;
	
	return curr;
}

void pushHead(char k)
{
	curr = newNode(k);

	if(head==NULL) // first data
	{
		head = tail = curr;
	}
	else // not the first data
	{
		curr->next = head;
		head = curr;
	}
}

void displayAll()
{
	curr = head;
	while(curr) // Non-Zero => True
	{
		printf("%c ", curr->k);
		curr = curr->next;
	}
}
