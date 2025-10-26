#include <stdio.h>

int scanSurrounding(char grid[101][101], int x, int y, int n, int m)
{
    int flooded = 0;
    if (x >= n || y >= m || x < 0 || y < 0)
    {
        return flooded;
    }

    if (grid[x][y] == '#')
    {
        return flooded;
    }

    if (grid[x][y] == '.')
    {
        flooded = 1;
    }

    grid[x][y] = '#';

    flooded += scanSurrounding(grid, x - 1, y, n, m);
    flooded += scanSurrounding(grid, x, y + 1, n, m);
    flooded += scanSurrounding(grid, x + 1, y, n, m);
    flooded += scanSurrounding(grid, x, y - 1, n, m);

    return flooded;
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        char houseGrid[101][101];
        for (int i = 0; i < n; i++)
        {
            scanf("%s", houseGrid[i]);
        }

        int x, y;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (houseGrid[i][j] == 'S')
                {
                    x = i;
                    y = j;
                    i = n;
                    break;
                }
            }
        }

        int tiles = scanSurrounding(houseGrid, x, y, n, m);
        printf("Case #%d: %d\n", t, tiles);
    }

    return 0;
}