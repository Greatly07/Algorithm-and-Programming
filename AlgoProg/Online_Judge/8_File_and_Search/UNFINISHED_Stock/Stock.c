#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char name[51];
    int stock;
} Product;

int main()
{
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL)
    {
        printf("there is no file found");
        return 0;
    }

    int testCases;
    fscanf(fp, "%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        int n;
        fscanf(fp, "%d\n", &n);

        Product database[n];
        int length = 0;
        bool outtaStock = false;
        printf("Case #%d:\n", t);
        for (int i = 0; i < n; i++)
        {
            char state[5];
            fscanf(fp, "%[^#]#", state);
            if (strcmp(state, "buy") == 0)
            {
                char produce[51];
                int proStock;
                fscanf(fp, "%[^#]#%d\n", produce, &proStock);

                int found = -1;
                for (int j = 0; j < length; j++)
                {
                    if (strcmp(produce, database[j].name) == 0)
                    {
                        found = j;
                        break;
                    }
                }

                if (found != -1)
                {
                    database[found].stock += proStock;
                }
                else
                {
                    strcpy(database[length].name, produce);
                    database[length].stock = proStock;
                    length++;
                }
            }
            else
            {
                char produce[51];
                int proStock;
                fscanf(fp, "%[^#]#%d\n", produce, &proStock);

                int found = -1;
                for (int j = 0; j < length; j++)
                {
                    if (strcmp(produce, database[j].name) == 0)
                    {
                        found = j;
                        break;
                    }
                }

                if (found != -1)
                {
                    if (database[found].stock >= proStock)
                    {
                        database[found].stock -= proStock;
                    }
                    else
                    {
                        printf("stock is not enough for product %s\n", produce);
                        outtaStock = true;
                    }
                }
                else
                {
                    printf("stock is not enough for product %s\n", produce);
                    outtaStock = true;
                }
            }
        }
        if (!outtaStock)
        {
            for (int i = 0; i < length; i++)
            {
                printf("%s - %d\n", database[i].name, database[i].stock);
            }
        }
    }
    fclose(fp);

    return 0;
}