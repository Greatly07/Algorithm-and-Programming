#include <stdio.h>

int main()
{
    int x, y, k;

    scanf("%d %d %d", &x, &y, &k);

    int elv1 = k - x;
    int elv2 = y - k;

    if (elv1 == elv2 & elv1 >= 0 & elv2 >= 0)
    {
        printf("%d\n", elv1);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}