#include <stdio.h>

void printReverse(char str[], int number)
{
    if (str[number] == '\0')
    {
        return;
    }

    char letter = str[number];
    printReverse(str, number + 1);
    printf("%c", letter);

    return;
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        char str[1001];
        scanf(" %[^\n]", str);

        printf("Case #%d: ", t);
        printReverse(str, 0);
        printf("\n");
    }

    return 0;
}