#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    scanf("%s", str);

    int start = (strlen(str) / 2) - 2;

    printf("Midfix: ");
    for (int i = start; i < start + 5; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}