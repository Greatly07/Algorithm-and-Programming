#include <stdio.h>

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

        int n, a, b;
        fscanf(fp, "%d %d %d", &n, &a, &b);

        char arr[n + 1];
        fscanf(fp, "%s", arr);
        int counter = 0;
        int lightning = 0;
        for (int i = 0; i <= n; i++)
        {
            if (arr[i] == '1')
            {
                counter++;
            }
            else
            {
                if (counter >= a && counter <= b)
                {
                    lightning++;
                }
                counter = 0;
            }
        }
        printf("Case #%d: %d\n", t, lightning);
    }
    fclose(fp);

    return 0;
}