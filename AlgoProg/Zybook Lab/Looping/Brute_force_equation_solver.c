#include <stdio.h>

int main()
{
    int x1, y1, result1;
    scanf("%d %d %d", &x1, &y1, &result1);

    int x2, y2, result2;
    scanf("%d %d %d", &x2, &y2, &result2);

    int found = 0;
    for (int i = -10; i <= 10; i++)
    {
        for (int j = -10; j <= 10; j++)
        {
            if ((x1 * i) + (y1 * j) == result1 && (x2 * i) + (y2 * j) == result2)
            {
                printf("x = %d, y = %d\n", i, j);
                found = 1;
                return 0;
            }
        }
    }

    printf("There is no solution\n");

    return 0;
}