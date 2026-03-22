#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

typedef struct
{
	char letter;
	int count;
} Alphabet;

Alphabet *table[SIZE];

Alphabet *newNode(char letter)
{
	Alphabet *newAlphabet = (Alphabet *)malloc(sizeof(Alphabet));

	newAlphabet->letter = letter;
	newAlphabet->count = 1;

	return newAlphabet;
}

void insert(char letter)
{
	int hashKey = letter % SIZE;

	while (table[hashKey] != NULL)
	{
		if (table[hashKey]->letter == letter)
		{
			table[hashKey]->count += 1;
			return;
		}
		hashKey = (hashKey + 1) % SIZE;
	}

	table[hashKey] = newNode(letter);
}

void printResult()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (table[i] != NULL)
		{
			printf("%c %d\n", table[i]->letter, table[i]->count);
		}
	}
}

int main()
{
	char letter;

	while (scanf("%c", &letter) == 1 && letter != '\n')
	{
		insert(letter);
	}
	printResult();

	return 0;
}
