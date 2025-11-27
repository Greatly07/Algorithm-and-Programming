#include <stdio.h>
#include <string.h>

int main(void)
{
    char ch;
    char str[50];
    scanf("%c %s", &ch, str);

    int chCounter = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ch)
        {
            chCounter += 1;
        }
    }

    if (chCounter == 1)
    {
        printf("%d %c\n", chCounter, ch);
    }
    else
    {
        printf("%d %c\'s\n", chCounter, ch);
    }

    return 0;
}