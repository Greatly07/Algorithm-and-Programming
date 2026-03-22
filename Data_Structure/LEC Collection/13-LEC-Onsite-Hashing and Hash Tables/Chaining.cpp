#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 97

//1. data : name 
//2. name->sum of ascii->index/key
//3. hash function = division
//4. collision = chaining
//5. size hashtable : 97

struct H
{
	char s[100];
	struct H *next;
} *head[SIZE], *curr, *temp, *tail[SIZE]; //tiap element ""

int hash(char name[])
{//1. data : name 
	int i, n = strlen(name);
	int idx = 0; // result
	int sumASCII = 0;
	
	//2. name->sum of ascii->index/key
	for(i = 0; i < n; i++)
	{
		sumASCII += name[i];
	}	
	
	//3. hash function = division
	idx = sumASCII % SIZE;
	//5. size hashtable : 97
	return idx;
}

struct H * newNode(char s[])
{
	curr = (struct H *) malloc (sizeof(struct H));
	strcpy(curr->s, s);
	curr->next = NULL;	
};

void pushHashTable(char s[]) // PushHead
{	
	int idx;
	idx = hash(s);
		
	curr = newNode(s);
	
	if(head[idx]==NULL)
	{
		head[idx] = tail[idx] = curr;
	}
	else
	{
		tail[idx]->next = curr;
		tail[idx] = curr;
	}
}

void display()
{
	int i, headerFlag=1;
	for(i = 0; i < SIZE; i++)
	{
		if(head[i] == NULL) continue;
		if((strcmp(head[i]->s, "") != 0) )
		{
			if(headerFlag)
			{
				printf("| idx  | String\n");
				headerFlag = !headerFlag;
			}
	
			printf("| %4d | ", i);
			curr = head[i];
			while (curr) 
			{
				printf("%10s", curr->s);
				curr = curr->next;
				if(curr) printf(" "); //masih ada data selanjutnya
				else printf("\n"); //data terakhir
			}			
		}
	}
}

int findHashTable(char s[]) //return subidx 
{
	int subidx = 0;
	int idx = hash(s);
	curr = head[idx];
	while(curr) 
	{
		if(strcmp(curr->s, s) == 0) break;
		subidx++;
		curr = curr->next;		
	}
	if (curr) return subidx; //found
	else return -1;
}

void pop(int idx, int subidx)
{
	if(subidx == -1) return;

	curr = head[idx]; 
	int i=0;
	while (curr) 
	{
		if(i == subidx) break; 
		
		temp = curr;
		curr = curr->next;	//temp node sebelum curr, curr node yg ingin dipop
		
		i++;
	}
	
	if(curr)
	{
		if (curr == head[idx] && curr == tail[idx]) // data yg dihapus ada di head, data satu2-nya
		{
			head[idx] = tail[idx] = NULL;
		}
		else if (curr == head[idx]) //pophead
		{					     	
			head[idx] = curr->next;
		}
		else // popTail dan popMid
		{
			temp->next = curr->next;
		}
		free(curr);
	}
}

void popHashTable(char s[])
{
	struct H* curr;
	int idx = hash(s);
	int subidx = findHashTable(s);	
	
	printf("%d %d", idx, subidx);
	getchar();
	
	pop(idx, subidx);
}

void popAll( )
{
	int i;
	for(i=0; i<SIZE; i++)	
	{
		while(head[i])
		{
			curr = head[i];
			if (head[i] == tail[i]) // data yg dihapus ada di head, data satu2-nya
			{
				head[i] = tail[i] = NULL;
			}
			else // bkn data satu2nya
			{					     	
				head[i] = curr->next;
			}
			free(curr);		
		}			
	}
}



int main(){
	int choice = 0;
	char s[100];
		
	do{
		system("cls");
		printf("SIZE HASHTABLE : %d\n", SIZE);
		display();
		puts("");
		printf("Hashing - Chaining\n");
		printf("1. Insert String to Hash\n");
		printf("2. Find Hash Value\n");
		printf("3. Delete String from Hash\n");
		printf("4. popAll\n");
		printf("0. Exit\n");
		printf("Choice = ");
		scanf("%d", &choice); getchar();
		
		switch(choice){
			case 1:
				printf("string? ");
				gets(s);
				
				pushHashTable(s);
				
				break;
				
			case 2:
				printf("string? ");
				gets(s);
				
				if(findHashTable(s) != -1) printf("idx of %s : %d, found at subidx %d\n", s, hash(s), findHashTable(s));
				else printf("not exist");
				getchar();
				break;
			
			case 3:
				printf("string? ");
				gets(s);
				
				popHashTable(s);
				break;	
			case 4:
				popAll();
				break;
		}
	}while(choice != 0);
	popAll();
	return 0;
}
