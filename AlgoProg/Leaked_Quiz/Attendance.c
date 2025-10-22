#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int room[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &room[i][j]);
        }
    }

    int teamCount[n];
    for (int i = 0; i < n; i++)
    {
        teamCount[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (room[i][j] != 0)
            {
                teamCount[room[i][j] - 1] += 1;
            }
        }
    }

    int incompleteTeam = 0;
    for (int i = 0; i < n; i++)
    {
        if (teamCount[i] < n)
        {
            incompleteTeam += 1;
        }
    }

    printf("%d\n", incompleteTeam);

    return 0;
}