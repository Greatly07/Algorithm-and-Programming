#include <stdio.h>
#include <string.h>

int isVowel(char c)
{
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main()
{
    int testCases;
    scanf("%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        char str[1001];
        scanf("%s", str);
        int len = strlen(str);

        char message[len + 1];
        message[len] = '\0';
        int key[len];

        for (int i = 0; i < len; i++)
        {

            if (isVowel(str[i]))
            {
                message[i] = str[i];
                key[i] = 0;
            }
            else
            {
                char curr = str[i];
                key[i] = 0;
                while (!isVowel(curr))
                {
                    curr--;
                    key[i]++;
                }
                message[i] = curr;
            }
        }

        printf("Case #%d:\n", t);
        printf("%s\n", message);
        for (int i = 0; i < len; i++)
        {
            printf("%d", key[i]);
        }
        printf("\n");
    }
    return 0;
}