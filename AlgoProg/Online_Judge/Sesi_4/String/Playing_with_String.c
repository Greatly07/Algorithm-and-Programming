#include <stdio.h>
#include <string.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        char str[10001];
        int n;
        scanf("%s %d", str, &n);

        for (int i = 0; i < n; i++)
        {
            char b, a;
            scanf(" %c %c", &b, &a);
            for (int j = 0; j < strlen(str); j++)
            {
                if (str[j] == b)
                {
                    str[j] = a;
                }
            }
        }
        printf("Case #%d: %s\n", t, str);
    }

    return 0;
}