#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t size = 10000001; // constraint length + \0
    char *str = (char *)malloc(size * sizeof(char));
    scanf("%s", str);

    if (str == NULL)
    {
        return 1; // malloc failed
    }

    int charBin[256] = {0};
    for (int i = 0; str[i] != '\0'; i++)
    {
        charBin[str[i]]++;
    }

    for (char i = 'A'; i <= 'Z'; i++)
    {
        while (charBin[i] > 0)
        {
            printf("%c", i);
            charBin[i]--;
        }

        char lowCase = i + 32;
        while (charBin[lowCase] > 0)
        {
            printf("%c", lowCase);
            charBin[lowCase]--;
        }
    }

    free(str);
    return 0;
}