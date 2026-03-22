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
struct Data *newNode(char k);
void pushTail(char k);
void popHead();
void popAll();
char peekHead(); // front(); return front data / first pushed data if exist, else return -1
int size(); // numNodes in stack lists  
int is_empty(); // return 1 if size() == 0, else return 0
int is_full(); // return 1 if size() == FULL, else return 0
void displayInfoAndData();
void menu();
void menu1(); //pushTail
void popMin();

int main()
{
	int pilih, i;
	char kata[100]={0};
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
			case 3 : printf("\npeekChar() : '%c'\n", peekHead()); getchar(); break;
			case 4 : popMin(); break;
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
			pushTail(kata[i]);
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
		printf("Queue\n");
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
	printf("1. Input Kata, push char ke queue [max 10 kar]\n");
	printf("2. PopQueue\n");
	printf("3. PeekHead\n");
	printf("4. PopMin\n");
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
	if(head==NULL)
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

char peekHead()
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

void popMin()
{
	if(head == NULL) return;
	
	curr = head;
	struct Data *temp, *min, *beforemin;
	char min_k = head->k;
	min = curr;			
	
	while(curr)
	{
		if(curr->k < min_k)
		{
			min_k = curr->k;
			beforemin = temp;
			min = curr;			
		}
		temp = curr;
		curr = curr->next;	
	}
	curr = min;
	
	if(curr == head && curr == tail) // last data
	{
		head = tail = NULL;
		
	}
	else // not the last data
	{
		if (curr == head) // popHead
		{
			head = head->next;	
		}
		else if (curr == tail) // popTail
		{
			temp = beforemin;			
			tail = temp;
			tail->next = NULL;
		}
		else // mid 
		{
			temp = beforemin; 			
			temp->next = curr->next;
		}
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

void pushTail(char k)
{
	curr = newNode(k);

	if(head == NULL) // data pertama
	{
		head = tail = curr;
	}
	else
	{
		tail->next = curr;
		tail = curr;
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
