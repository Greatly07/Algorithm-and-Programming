#include <stdio.h>
#include <string.h>

typedef struct
{
    char id[13];
    char name[23];
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
    fscanf(fp, "%d", &n);

    Student database[103];
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%s %s", database[i].id, database[i].name);
    }

    int testCases;
    fscanf(fp, "%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        char studentId[13];
        fscanf(fp, "%s", studentId);

        printf("Case #%d: ", t);
        // BINARY SEARCH
        int left = 0;
        int right = n - 1;
        // DONT SET found TO 0
        int found = -1;
        while (left <= right)
        {
            int middle = ((right - left) / 2) + left;
            int studentCmp = strcmp(studentId, database[middle].id);
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
            printf("%s\n", database[found].name);
        }
        else
        {
            printf("N/A\n");
        }
    }
    fclose(fp);

    return 0;
}