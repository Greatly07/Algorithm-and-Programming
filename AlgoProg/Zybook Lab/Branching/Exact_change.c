#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n == 0 || n < 0)
    {
        printf("No change\n");
        return 0;
    }
    if (n >= 100)
    {
        int dollar = n / 100;
        n %= 100;
        printf("%d Dollar%s\n", dollar, dollar == 1 ? "" : "s");
    }
    if (n >= 25)
    {
        int quarter = n / 25;
        n %= 25;
        printf("%d Quarter%s\n", quarter, quarter == 1 ? "" : "s");
    }
    if (n >= 10)
    {
        int dime = n / 10;
        n %= 10;
        printf("%d Dime%s\n", dime, dime == 1 ? "" : "s");
    }
    if (n >= 5)
    {
        int nickel = n / 5;
        n %= 5;
        printf("%d Nickel%s\n", nickel, nickel == 1 ? "" : "s");
    }
    if (n >= 1)
    {
        printf("%d Penn%s\n", n, n == 1 ? "y" : "ies");
    }

    return 0;
}