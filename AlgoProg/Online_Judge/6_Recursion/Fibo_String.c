#include <stdio.h>
#include <string.h>

void fibo(int n, char let1, char let2)
{
    if (n == 0)
    {
        printf("%c", let1);
        return;
    }
    if (n == 1)
    {
        printf("%c", let2);
        return;
    }

    fibo(n - 1, let1, let2);
    fibo(n - 2, let1, let2);

    return;
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int n;
        scanf("%d", &n);

        char letter1;
        char letter2;
        scanf(" %c %c", &letter1, &letter2);

        printf("Case #%d: ", t);
        fibo(n, letter1, letter2);
        printf("\n");
    }

    return 0;
}