#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int i = 1; i <= testCases; i++)
    {
        int x;
        scanf("%d", &x);

        for (int row = 1; row <= x; row++)
        {
            for (int column = 1; column <= x - row; column++)
            {
                printf(" ");
            }
            for (int column = 1; column <= row - 1; column++)
            {
                printf("*");
            }
            for (int column = 1; column <= row; column++)
            {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}