#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[41];
    char tree[41];
} Student;

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

    Student database[101];
    for (int k = 0; k < n; k++)
    {
        fscanf(fp, "%[^#]#%[^\n]\n", database[k].name, database[k].tree);
    }

    int testCases;
    fscanf(fp, "%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        char studentName[41];
        fscanf(fp, "%s", studentName);

        printf("Case #%d: ", t);
        // BINARY SEARCH
        int left = 0;
        int right = n - 1;
        int found = -1;
        while (left <= right)
        {
            int middle = ((right - left) / 2) + left;
            int studentCmp = strcmp(studentName, database[middle].name);
            if (studentCmp == 0)
            {
                found = middle;
                break;
            }
            else if (studentCmp < 0)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        if (found != -1)
        {
            printf("%s\n", database[found].tree);
        }
        else
        {
            printf("N/A\n");
        }
    }
    fclose(fp);

    return 0;
}