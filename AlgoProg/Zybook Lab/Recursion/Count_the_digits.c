#include <stdio.h>

/* TODO: Write recursive DigitCount() function here. */
int DigitCount(int n)
{
    if (n < 10)
    {
        return 1;
    }

    return 1 + DigitCount(n / 10);
}

int main(void)
{
    int num;
    int digits;

    scanf("%d", &num);
    digits = DigitCount(num);
    printf("%d", digits);
    return 0;
}
