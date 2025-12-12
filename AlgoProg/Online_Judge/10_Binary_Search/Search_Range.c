#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[256];
    int score;
} Student;

int binarySearch(Student datab[], int n, char name[])
{
    int left = 0;
    int right = n - 1;
    int found = -1;
    while (left <= right)
    {
        int middle = ((right - left) / 2) + left;
        int studentCmp = strcmp(name, datab[middle].name);
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

    return found;
}

int main()
{
    int stSize;
    scanf("%d", &stSize);
    Student database[stSize];
    for (int i = 0; i < stSize; i++)
    {
        scanf("%s %d", database[i].name, &database[i].score);
    }

    int testCases;
    scanf("%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        char studentname[256];

        scanf("%s", studentname);
        int pos1 = binarySearch(database, stSize, studentname);

        scanf("%s", studentname);
        int pos2 = binarySearch(database, stSize, studentname);

        int invalid = 0;
        if (pos1 < 0 || pos2 < 0)
        {
            printf("not found\n");
            invalid = 1;
        }
        else if (pos1 == pos2)
        {
            printf("not valid\n");
            invalid = 1;
        }

        if (!invalid)
        {
            int scoreGap = database[pos1].score - database[pos2].score;
            if (scoreGap < 0)
            {
                scoreGap *= -1;
            }

            int lbGap = pos1 - pos2;
            if (lbGap < 0)
            {
                lbGap *= -1;
            }

            printf("%d %d\n", scoreGap, lbGap);
        }
    }

    return 0;
}