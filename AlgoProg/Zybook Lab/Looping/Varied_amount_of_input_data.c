#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int max = 0;
    double average = 0;
    int counter = 0;
    while (n > -1)
    {
        average += (double)n;
        if (n > max)
        {
            max = n;
        }
        scanf("%d", &n);
        counter += 1;
    }
    average /= (double)counter;

    printf("%d %.2lf\n", max, average);

    return 0;
}