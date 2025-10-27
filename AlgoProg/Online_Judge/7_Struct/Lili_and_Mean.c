#include <stdio.h>

typedef struct
{
    char id[11];
    char name[16];
    int score;
} TestScore;

int main()
{
    int n;
    scanf("%d", &n);

    TestScore database[n + 1];
    double mean = 0;
    for (int t = 1; t <= n; t++)
    {
        scanf("%s", database[t].id);
        getchar();
        scanf("%[^\n]", database[t].name);
        scanf("%d", &database[t].score);

        mean += (double)database[t].score;
    }
    mean = mean / (double)n;

    for (int i = 1; i <= n; i++)
    {
        if (database[i].score >= mean)
        {
            printf("%s %s\n", database[i].id, database[i].name);
        }
    }

    return 0;
}