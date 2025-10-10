#include <stdio.h>

int main()
{
    int a, b, c, max;
    scanf("%d %d %d", &a, &b, &c);
    max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    printf("Max of [%d, %d, %d] is %d\n", a, b, c, max);

    return 0;
}