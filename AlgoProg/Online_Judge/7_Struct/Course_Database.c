#include <stdio.h>

typedef struct
{
    char code[9];
    char name[101];
    int credits;
} Course;

int main()
{
    int n;
    scanf("%d", &n);

    Course database[1001];

    for (int i = 1; i <= n; i++)
    {
        scanf("%s", database[i].code);
        getchar();
        scanf("%[^\n]", database[i].name);
        scanf("%d", &database[i].credits);
    }

    int query;
    scanf("%d", &query);

    for (int t = 1; t <= query; t++)
    {
        int index;
        scanf("%d", &index);

        printf("Query #%d:\n", t);
        printf("Code: %s\n", database[index].code);
        printf("Name: %s\n", database[index].name);
        printf("Credits: %d\n", database[index].credits);
    }

    return 0;
}