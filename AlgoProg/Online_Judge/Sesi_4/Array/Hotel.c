#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int rooms[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &rooms[i]);
    }

    int happy = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (rooms[i] != rooms[j])
            {
                if (j == i - 1)
                {
                    happy++;
                }
            }
            else
            {
                break;
            }
        }
    }

    printf("%d\n", happy);
    return 0;
}