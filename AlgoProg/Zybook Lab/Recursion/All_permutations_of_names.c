#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int MAX_NAME_SIZE = 50;

// TODO: Write function to create and output all permutations of the list of names.
void PrintAllPermutations(char **permList, int permSize, char **nameList, int nameSize)
{
    if (nameSize == 0)
    {
        printf("%s", permList[0]);
        for (int i = 1; i < permSize; i++)
        {
            printf(", %s", permList[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; i < nameSize; ++i)
        {
            permList[permSize] = nameList[i];

            char *remainingNames[nameSize - 1];
            int k = 0;
            for (int j = 0; j < nameSize; ++j)
            {
                if (j != i)
                {
                    remainingNames[k] = nameList[j];
                    k++;
                }
            }

            PrintAllPermutations(permList, permSize + 1, remainingNames, nameSize - 1);
        }
    }
}

int main(void)
{
    int size;
    int i = 0;
    char name[MAX_NAME_SIZE];
    scanf("%d", &size);
    char *nameList[size];
    char *permList[size];

    for (i = 0; i < size; ++i)
    {
        nameList[i] = (char *)malloc(MAX_NAME_SIZE);
        scanf("%s", name);
        strcpy(nameList[i], name);
    }

    PrintAllPermutations(permList, 0, nameList, size);

    // Free dynamically allocated memory
    for (i = 0; i < size; ++i)
    {
        free(nameList[i]);
    }

    return 0;
}