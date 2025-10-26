#include <stdio.h>
#include <string.h>
#include <ctype.h>

int reversed(char str[])
{
    int len = strlen(str);
    char str2[len + 1];
    strcpy(str2, str);

    for (int i = 0; i < len / 2; i++)
    {
        char temp = str2[i];
        str2[i] = str2[len - i - 1];
        str2[len - i - 1] = temp;
    }
    if (strcmp(str, str2) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        char str[501];
        scanf("%s", str);
        printf("Case #%d: ", t);
        if (reversed(str))
        {
            printf("Yay, it's a palindrome\n");
        }
        else
        {
            printf("Nah, it's not a palindrome\n");
        }
    }

    return 0;
}