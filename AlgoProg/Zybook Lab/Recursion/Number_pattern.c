#include <stdio.h>

/* Define PrintNumPattern() here */
void PrintNumPattern(int x, int y)
{
    printf("%d", x);
    if (x >= 0)
    {
        printf(" ");
        PrintNumPattern(x - y, y);
        printf(" %d", x);
    }
}

int main(void)
{
    int num1;
    int num2;

    scanf("%d", &num1);
    scanf("%d", &num2);
    PrintNumPattern(num1, num2);
    printf("\n");

    return 0;
}