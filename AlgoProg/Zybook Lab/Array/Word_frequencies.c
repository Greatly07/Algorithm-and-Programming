#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    char str[n + 1][21];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }

    int freq[n];
    for (int i = 0; i < n; i++)
    {
        freq[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (strcmp(str[i], str[j]) == 0)
            {
                freq[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s - %d\n", str[i], freq[i]);
    }

    return 0;
}