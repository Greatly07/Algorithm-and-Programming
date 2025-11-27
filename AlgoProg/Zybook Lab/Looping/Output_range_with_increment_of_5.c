#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    if (n > m)
    {
        printf("Second integer can\'t be less than the first.\n");
        return 0;
    }

    while (n <= m)
    {
        printf("%d ", n);
        n += 5;
    }
    printf("\n");

    return 0;
}