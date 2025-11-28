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

        Product database[100];
        int length = 0;
        bool outtaStock = false;
        printf("Case #%d:\n", t);
        for (int i = 0; i < n; i++)
        {
            char state[7];
            char produce[51];
            int proStock;
            fscanf(fp, " %[^#]#%[^#]#%d", state, produce, &proStock);

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
                if (strcmp(state, "buy") == 0)
                {
                    database[found].stock += proStock;
                } // if not then sell
                else
                {
                    database[found].stock -= proStock;
                }
            }
            else
            {
                if (strcmp(state, "sell") == 0)
                {
                    proStock = -proStock;
                }
                strcpy(database[length].name, produce);
                database[length].stock = proStock;
                length++;
            }
        }

        for (int i = 0; i < length; i++)
        {
            if (database[i].stock < 0)
            {
                outtaStock = true;
                break;
            }
        }

        if (!outtaStock)
        {
            for (int i = 0; i < length; i++)
            {
                printf("%s - %d\n", database[i].name, database[i].stock);
            }
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                if (database[i].stock < 0)
                {
                    printf("stock is not enough for product %s\n", database[i].name);
                }
            }
        }
    }

    fclose(fp);

    return 0;
}