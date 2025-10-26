#include <stdio.h>

int main()
{
    for (int i = 0; i < 3; i++)
    {
        float a, b, c, d;
        scanf("%f %f %f %f", &a, &b, &c, &d);

        float sum = (2 * (a / 1)) + (4 * (b / 2)) + (6 * (c / 3)) + (4 * (d / 4));

        printf("%.2f\n", sum);
    }

    return 0;
}