#include <stdio.h>

int main()
{
    int m;
    scanf("%d", &m);

    long long int numberList[m];
    for (int i = 0; i < m; i++)
    {
        scanf(" %lld", &numberList[i]);
    }

    int isEven[m];
    for (int i = 0; i < m; i++)
    {
        if (numberList[i] % 2 == 0)
        {
            isEven[i] = 1;
        }
        else
        {
            isEven[i] = 0;
        }
    }

    int firstPrint = 1;
    for (int i = 0; i < m; i++)
    {
        if (isEven[i] == 0)
        {
            if (firstPrint == 1)
            {
                printf("%lld", numberList[i]);
                firstPrint = 0;
            }
            else
            {
                printf(" %lld", numberList[i]);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (isEven[i] == 1)
        {
            if (firstPrint == 1)
            {
                printf("%lld", numberList[i]);
                firstPrint = 0;
            }
            else
            {
                printf(" %lld", numberList[i]);
            }
        }
    }
    printf("\n");

    return 0;
}