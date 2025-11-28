#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL)
    {
        printf("there is no file found");
        return 0;
    }

    int testCases;
    fscanf(fp, "%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        int strChecker[26] = {0};
        char str[101];
        fscanf(fp, "%s", str);
        int strLen = strlen(str);

        int n;
        fscanf(fp, "%d", &n);
        for (int i = 0; i < n; i++)
        {
            char a, b;
            fscanf(fp, " %c %c", &a, &b);
            if (strChecker[a - 'A'] == 0)
            {
                for (int j = 0; j < strLen; j++)
                {
                    if (str[j] == a)
                    {
                        str[j] = b;
                    }
                }
                strChecker[a - 'A'] = 1;
            }
        }

        int charBin[26] = {0};
        for (int i = 0; i < strLen; i++)
        {
            charBin[str[i] - 'A']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (charBin[i] > 0)
            {
                printf("%c %d\n", (char)(i + 'A'), charBin[i]);
            }
        }
    }
    fclose(fp);

    return 0;
}