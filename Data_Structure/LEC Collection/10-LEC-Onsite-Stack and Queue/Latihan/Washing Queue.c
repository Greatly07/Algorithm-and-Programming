#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>
#include <string.h>

char type[2][10]={"regular", "vip"};

struct Data
{
	int t;//0 = regular, vip = 1
	char plate[50];
	struct Data *next, *prev;
} *head, *curr, *tail;

int totalIncome=0;
int n=0;
	
void display()
{
	int i=1;

	if(head)
	{
		curr = head;
		while(curr)
		{
			printf("%d. %10s : %10s\n", i, type[curr->t], curr->plate);
			curr = curr->next;
			i++; 
		}
	}
	else
	{
		printf("No Motorcycle\n");
	}
	printf("\n");
}

void menu()
{
	printf("Washing Queue\n");
	printf("=============\n");
	printf("1. Add reguler / vip motorcycle to washing queue\n");
	printf("2. Wash motorcycle from washing queue (priority : VIP first)\n");
	printf("3. Cancel specific motorcycle from washing queue\n");
	printf("0. Wash All, Exit\n");
	printf("Pilih : ");
}

void pushTail(struct Data c)
{
	curr = (struct Data *) malloc(sizeof(struct Data));
	curr->t=c.t;
	strcpy(curr->plate, c.plate);
	curr->next = NULL;

	if (head == NULL)
	{		
		head = tail = curr;		
	}
	else
	{
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}
}

void popHead ()
{

	if(head)
	{	
		curr = head;		
		if(head == tail) 
		{
			head = tail = NULL;	
		}
		else
		{
			head = head -> next;
			head->prev = NULL;
		}
		free(curr);
	}
}

void popTail ()
{
	if(head)
	{	
		curr = tail;		
		if(head == tail) 
		{
			head = tail = NULL;	
		}
		else
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		free(curr);
	}
}

void popAll()
{
	while (head) popHead();
}

void menu1 ()
{
	struct Data c;
	char code[10], serial[10];
	int num;

	do
	{
		printf("Insert Plate  [Number between 3000-6999] : ");
		gets(c.plate); 
		sscanf(c.plate, "%s %d %s", code, &num, serial);
	} while (num<3000 || num>6999);

	//kode daerah [1-2 digit]	: B, F, D, AB, dsb
	//no						: 3000 - 6999 = motor
	//seri umum [2-3 digit]		: [Area,jenis kendaraan,dan kode pembeda] cth : BNS 
	// http://id.wikipedia.org/wiki/Tanda_nomor_kendaraan_bermotor
	
	do
	{
		printf("Insert Type [0 : regular, 1 : vip] : ");
		scanf("%d", &c.t); fflush(stdin);		
	} while (c.t<0 || c.t>1);
	
	pushTail(c);
	
}

void popPriority()
{
	int income=0;
	if(head)
	{	
		curr = head;
		while(curr)
		{
			if(curr->t == 1) break;
			curr = curr->next;
		}
		if(curr == NULL) curr = head; // no vip motor, then just wash regular motor
		
		if(curr == head && curr == tail) 
		{
			head = tail = NULL;
		}
		else
		{
			if(curr == head)
			{
				head = head -> next;
				head->prev = NULL;
			}
			else if (curr == tail)
			{
				tail = tail->prev;
				tail->next = NULL;
			}
			else
			{
				curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
			}
		}
		if(curr->t == 0) income = 10000;
		else if(curr->t == 1) income = 15000;
		
		printf("\n%s motorcycle-%10s is washed. %d is paid\n", type[curr->t], curr->plate, income);
		totalIncome += income;
		free(curr);
		getchar();
		return;
	}
}

void menu2()
{
	popPriority();
}

void popSearch (char plate[50])
{
	if(head)
	{	
		curr = head;
		while(curr)
		{
			if(strcmpi(curr->plate, plate) == 0) break;
			curr = curr->next;
		}
		
		if(curr)
		{
			if(curr == head && curr == tail) 
			{
				head = tail = NULL;	
			}
			else
			{
				if(curr == head)
				{
					head = head -> next;
					head->prev = NULL;
				}
				else if (curr == tail)
				{
					tail = tail->prev;
					tail->next = NULL;
				}
				else
				{
					curr->next->prev = curr->prev;
					curr->prev->next = curr->next;
				}
			}
			printf("\n%s motorcycle-%10s is canceled. \n", type[curr->t], curr->plate);
			free(curr);
			getchar();
			return;
		}
		else
		{
			printf("\n motorcycle-%10s is not found. \n", plate);
			getchar();
		}
	}
	
}

void menu3 ()
{
	char plate[50], code[10], serial[10];
	int num;

	do
	{
		printf("Insert Plate  [Number between 3000-6999] : ");
		gets(plate); 
		sscanf(plate, "%s %d %s", code, &num, serial);
	} while (num<3000 || num>6999);
	//kode daerah [1-2 digit]	: B, F, D, dsb
	//no						: 3000 - 6999 = motor
	//seri umum [2-3 digit]		: [Area,jenis kendaraan,dan kode pembeda] cth : BNS 
	// http://id.wikipedia.org/wiki/Tanda_nomor_kendaraan_bermotor
	
	popSearch(plate);
}

int numOfNodes()
{
	int n=0;
	struct Data *curr;
	if(head)
	{
		curr = head;
		while(curr)
		{
			curr = curr->next;
			n++;
		}
	}
	return n;
}


int main()
{
	int input;
	do
	{
		system("cls");
		display();
		n = numOfNodes();
		printf("\nTotal Queue: %10d ", n);
		if(n >= 5) printf("[Queue is FULL]\n");
		
		printf("\nTotal Income : %10d\n\n", totalIncome);
		menu();
		scanf("%d", &input); fflush(stdin);
		switch(input)
		{
			case 1 : if (n<5) { menu1(); } break;
			case 2 : if (n>0) { menu2(); } break;
			case 3 : if (n>0) { menu3(); } break;
		}
	} while (input != 0);
	popAll();
	return 0;
}
