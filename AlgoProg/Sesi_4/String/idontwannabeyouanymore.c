#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        int n;
        scanf("%d", &n);
        char name[n + 1];
        scanf(" %[^\n]", name);

        printf("Case #%d: ", t);
        for (int i = 0; i < strlen(name); i++)
        {
            if (isalpha(name[i]))
            {
                printf("%c", name[i]);
            }
        }

        printf("\n");
    }

    return 0;
}