#include <stdio.h>

int main(void)
{
    int n, smallest;
    scanf("%d", &n);
    smallest = n;
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &n);
        if (n < smallest)
        {
            smallest = n;
        }
    }
    printf("%d\n", smallest);

    return 0;
}