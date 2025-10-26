#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, g;

    scanf("%d %s %d %s %d %s %d %s %d %s %d %s", &a, &g, &b, &g, &c, &g, &d, &g, &e, &g, &f, &g);
    printf("%d\n%d\n%d\n", a + b, c + d, e + f);

    return 0;
}