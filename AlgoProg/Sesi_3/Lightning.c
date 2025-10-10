#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int i = 1; i <= testCases; i++)
    {
        int storage[7];
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &storage[j]);
        }

        printf("Case #%d: ", i);
        for (int j = 0; j < storage[0]; j++)
        {
            printf("a");
        }
        for (int j = 0; j < storage[1]; j++)
        {
            printf("s");
        }
        for (int j = 0; j < storage[2]; j++)
        {
            printf("h");
        }
        for (int j = 0; j < storage[3]; j++)
        {
            printf("i");
        }
        for (int j = 0; j < storage[4]; j++)
        {
            printf("a");
        }
        for (int j = 0; j < storage[5]; j++)
        {
            printf("p");
        }
        printf("\n");
    }

    return 0;
}