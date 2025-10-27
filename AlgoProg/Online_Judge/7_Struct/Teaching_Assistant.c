#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[200][11];
    int total;
} Group;

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int n;
        scanf("%d", &n);

        Group database[21];
        for (int i = 0; i < 21; i++)
        {
            database[i].total = 0;
        }

        for (int i = 0; i < n; i++)
        {
            char name[11];
            int groupNumber;
            scanf("%s %d", name, &groupNumber);

            int count = database[groupNumber].total;

            strcpy(database[groupNumber].name[count], name);

            database[groupNumber].total += 1;
        }

        printf("Case #%d:\n", t);
        for (int i = 1; i <= 20; i++)
        {
            if (database[i].total != 0)
            {
                printf("Group %d(%d):\n", i, database[i].total);
                for (int j = 0; j < database[i].total; j++)
                {
                    printf("%s\n", database[i].name[j]);
                }
            }
        }
    }

    return 0;
}