#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 97

//1. data : name 
//2. name->sum of ascii->index/key
//3. hash function = division
//4. collision = linear probing
//5. size hashtable : 97

char hashTable[SIZE][100]; //tiap element ""

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

void pushHashTable(char s[])
{	
	int idx, start;
	idx = start = hash(s);
	while(strcmp(hashTable[idx], "") != 0) 
	{
		idx++;
		idx = idx % SIZE;
		if (idx == start) 
		{
			printf("HashTable Full");
			getchar();
			return;
		}
	}	
	strcpy(hashTable[idx],s);
}

void display()
{
	int i, headerFlag=1;
	for(i = 0; i < SIZE; i++)
	{
		if((strcmp(hashTable[i], "") != 0) )
		{
			if(headerFlag)
			{
				printf("| idx  | String\n");
				headerFlag = !headerFlag;
			}
	
			printf("| %4d | %10s\n", i, hashTable[i]);
		}
	}
}

int findHashTable(char s[])
{
	int start;
	int idx = start = hash(s);
	
	while(strcmp(hashTable[idx], s) != 0) 
	{
		idx++;
		idx = idx % SIZE;		
		if(idx == start || strcmp(hashTable[idx], "") == 0 ) return -1; // if idx return to start idx, not found
		if(strcmp(hashTable[idx], s) == 0) break;
		
	}
	return idx;
}

void popHashTable(char s[])
{
	int idx = findHashTable(s);
	printf("%d", idx);
	getchar();
	if(idx !=-1) strcpy(hashTable[idx],"");
}

void popAll()
{
	int i;
	for(i=0; i<SIZE; i++)
	{
		strcpy(hashTable[i],"");
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
		printf("Hashing - Linear Probing\n");
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
				
				if(findHashTable(s) != -1) printf("idx of %s : %d, found at %d\n", s, hash(s), findHashTable(s));
				else printf("not exist");
				getchar();
				break;
			
			case 3:
				printf("string? ");
				gets(s);
				
				popHashTable(s);				
				break;	
			case 4:
				popAll(); break;
		}
	}while(choice != 0);
	popAll();
	return 0;
}
