#include <stdio.h>

/* TODO: Write recursive DrawTriangle() function here. */
void DrawTriangle(int baseLength)
{
    if (baseLength <= 0)
    {
        return;
    }

    DrawTriangle(baseLength - 2);

    int space = (19 - baseLength) / 2;
    for (int i = 1; i <= space; i++)
    {
        printf(" ");
    }
    for (int i = 1; i <= baseLength; i++)
    {
        printf("*");
    }
    printf("\n");
}

int main(void)
{
    int baseLength;

    scanf("%d", &baseLength);
    DrawTriangle(baseLength);
    return 0;
}