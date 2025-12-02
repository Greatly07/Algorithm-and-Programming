#include <stdio.h>
#include <string.h>

typedef struct
{
    int number;
    char name[41];
} Plant;

int main()
{
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL)
    {
        printf("there is no file found");
        return 0;
    }

    int n;
    fscanf(fp, "%d", &n);

    Plant database[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, " %d#%[^\n]", &database[i].number, database[i].name);
    }

    // Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(database[j].name, database[j + 1].name) > 0)
            {
                char tempName[41];
                strcpy(tempName, database[j].name);
                int tempNum = database[j].number;
                strcpy(database[j].name, database[j + 1].name);
                database[j].number = database[j + 1].number;
                strcpy(database[j + 1].name, tempName);
                database[j + 1].number = tempNum;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %s\n", database[i].number, database[i].name);
    }

    fclose(fp);

    return 0;
}