#include <stdio.h>

int main()
{
    char word[4];
    for (int i = 0; i < 3; i++)
    {
        scanf(" %s", word);

        printf("%c\n", word[1]);
    }

    return 0;
}