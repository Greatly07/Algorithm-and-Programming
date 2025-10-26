#include <stdio.h>

int main()
{
    char n[11];
    char m[101];
    char c;
    int o;

    scanf("%s", n);
    // use getchar(); for safer string newline
    scanf(" %[^\n]", m);
    // use getchar(); for safer string newline
    scanf(" %c %d", &c, &o);

    printf("Id    : %s\n", n);
    printf("Name  : %s\n", m);
    printf("Class : %c\n", c);
    printf("Num   : %d\n", o);

    return 0;
}