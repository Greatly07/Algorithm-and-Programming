#include <stdio.h>
#include <string.h>

typedef struct
{
    char word[55];
    char original[55];
} shortWord;

int main()
{
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL)
    {
        printf("there is no file found");
        return 0;
    }

    int n;
    fscanf(fp, "%d\n", &n);

    shortWord correction[105];
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%[^#]#%[^\n]\n", correction[i].word, correction[i].original);
    }

    int testCases;
    fscanf(fp, "%d\n", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        char sentence[105];
        fscanf(fp, "%[^\n]\n", sentence);
        int sentenceLen = strlen(sentence);

        printf("Case #%d:\n", t);
        char str[105];
        int minus = 0;
        for (int i = 0; i <= sentenceLen; i++)
        {
            if (sentence[i] != ' ' && sentence[i] != '\0')
            {
                str[i - minus] = sentence[i];
                str[(i - minus) + 1] = '\0';
            }
            else
            {
                if (minus)
                {
                    printf(" ");
                }

                minus = i + 1;
                int found = 0;
                for (int j = 0; j < n; j++)
                {
                    if (strcmp(str, correction[j].word) == 0)
                    {
                        printf("%s", correction[j].original);
                        found = 1;
                        break;
                    }
                }
                if (found == 0)
                {
                    printf("%s", str);
                }
            }
        }
        printf("\n");
    }
    fclose(fp);

    return 0;
}