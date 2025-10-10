#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int i = 1; i <= testCases; i++)
    {
        int price, discount, max;
        scanf("%d %d %d", &price, &discount, &max);

        int final = (price / 100) * discount;

        printf("Case #%d: ", i);
        if (final > max)
        {
            printf("%d", max);
        }
        else
        {
            printf("%d", final);
        }
        printf("\n");
    }

    return 0;
}