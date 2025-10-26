#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    long long int damage = 0;
    for (int i = 0; i < n; i++)
    {
        damage += 100 + (i * 50);
    }

    printf("%lld\n", damage);

    return 0;
}