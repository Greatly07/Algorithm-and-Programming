#include <stdio.h>
#include <string.h>

int isEven(int c)
{
    return c % 2 == 0;
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        char str[100001];
        scanf(" %s", str);
        int len = strlen(str);

        int bin[256] = {0};
        for (int i = 0; i < len; i++)
        {
            bin[(unsigned char)str[i]] = 1;
        }

        int count = 0;
        for (int i = 0; i < 256; i++)
        {
            if (bin[i] == 1)
            {
                count++;
            }
        }

        printf("Case #%d: ", t);
        if (isEven(count))
        {
            printf("Yay\n");
        }
        else
        {
            printf("Ewwww\n");
        }
    }

    return 0;
}