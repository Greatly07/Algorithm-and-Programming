#include <stdio.h>

int main()
{
    double saving, interest;
    scanf("%lf %lf", &saving, &interest);

    for (int i = 0; i < 3; i++)
    {
        saving = saving + (saving * (interest / 100));
    }

    printf("%.2lf\n", saving);

    return 0;
}