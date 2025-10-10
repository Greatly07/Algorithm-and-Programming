#include <stdio.h>

int main()
{
    int a = 5;
    int b = 3;
    int n = a + b;
    int z = 0;

    if (n > 0 & a > b)
    {
        z = a;
    }
    else if (n > 0 & b >= a)
    {
        z = b;
    }

    printf("%d\n", z);

    return 0;
}