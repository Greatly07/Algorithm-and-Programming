#include <stdio.h>

int main()
{
    char name[101];
    scanf("%s", name); // if doesnt work try %[^\n] instead of %s

    printf("Halo %s\n", name);

    return 0;
}