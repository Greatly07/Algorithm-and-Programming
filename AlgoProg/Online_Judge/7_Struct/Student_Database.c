#include <stdio.h>

typedef struct
{
    char id[21];
    char name[101];
    int age;
} Student;

int main()
{
    int n;
    scanf("%d", &n);

    Student database[1001];

    for (int i = 1; i <= n; i++)
    {
        scanf("%s", database[i].id);
        getchar();
        scanf("%[^\n]", database[i].name);
        scanf("%d", &database[i].age);
    }

    int query;
    scanf("%d", &query);

    for (int t = 1; t <= query; t++)
    {
        int index;
        scanf("%d", &index);

        printf("Query #%d:\n", t);

        Student data = database[index];

        printf("ID: %s\n", data.id);
        printf("Name: %s\n", data.name);
        printf("Age: %d\n", data.age);
    }

    return 0;
}