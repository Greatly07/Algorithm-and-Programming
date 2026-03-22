#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LENGTH 100
#define SIZE 10

struct Mhs{
	char name[LENGTH];
	int age;
} *table[SIZE];

int count = 0;

struct Mhs *newNode(char name[LENGTH], int age){
	struct Mhs *newMhs = (Mhs*)malloc(sizeof(Mhs));
	strcpy(newMhs->name, name);
	newMhs->age = age;
	
	return newMhs;
}

int hash(char name[LENGTH]){
	int key = 0;
	int len = strlen(name);
	
	for(int i = 0; i < len; i++){
		key += name[i];
	}
	
	return key % SIZE;
}

void insert(char name[LENGTH], int age){
	int hashKey = hash(name);
	
	// cek apakah table nya full?
	if(count >= SIZE){
		printf("Table is full!\n");
		return;
	}
	
	while(table[hashKey] != NULL){
		hashKey = (hashKey + 1) % SIZE;
	}
	
	table[hashKey] = newNode(name, age);
	count++;
	printf("Data inserted successfully!\n");
}

void view(){
	for(int i = 0; i < SIZE; i++){
		if(table[i]){
			printf("%s - %d | hash: %d", table[i]->name, table[i]->age
			, hash(table[i]->name));
		} else {
			printf("-");
		}
		puts("");
	}
}

void add(){
	char name[LENGTH];
	int age;
	
	printf("Masukkan nama : ");
	scanf("%[^\n]", &name); getchar();
	printf("Masukkan umur : ");
	scanf("%d", &age); getchar();
	
	insert(name, age);
}

void remove(){
	char name[LENGTH];
	printf("Masukkan nama : ");
	scanf("%[^\n]", &name); getchar();
	
	int hashKey = hash(name);
	int pos = hashKey;
	
	do{
		if(table[pos] && strcmp(table[pos]->name, name) == 0){
			free(table[pos]);
			table[pos] = NULL;
			printf("Data removed successfully!\n");
			return;
		}
		pos = (pos + 1) % SIZE;
	} while(hashKey != pos);
	printf("Data not found!\n");
}

void search(){
	char name[LENGTH];
	printf("Masukkan nama : ");
	scanf("%[^\n]", &name); getchar();
	
	int hashKey = hash(name);
	int pos = hashKey;
	
	do{
		if(table[pos] && strcmp(table[pos]->name, name) == 0){
			printf("%s found at index - %d\n", table[pos]->name, pos);
			return;
		}
		pos = (pos + 1) % SIZE;
	} while(hashKey != pos);
	printf("Data not found!\n");
}

void menu(){
	int input = 0;
	do{
		system("cls");
		printf("Menu\n");
		printf("============\n");
		printf("1. Insert\n");
		printf("2. View\n");
		printf("3. Remove\n");
		printf("4. Search\n");
		printf("5. Exit\n");
		printf(">> ");
		scanf("%d", &input); getchar();
		
		switch (input){
			case 1:
				add();
				getchar();
				break;
			case 2:
				view();
				getchar();
				break;
			case 3:
				remove();
				getchar();
				break;
			case 4:
				search();
				getchar();
				break;
			case 5:
				printf("Thankyou for using this app!\n");
				getchar();
				break;
		}
		
	} while(input != 5);
	
	
}

int main(){
	menu();
	return 0;
}
