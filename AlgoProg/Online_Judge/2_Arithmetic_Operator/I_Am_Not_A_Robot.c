#include <stdio.h>

int main()
{
    float comments, robots;
    scanf("%f %f", &comments, &robots);

    float percentage = 100 / (comments / robots);

    printf("%.4f%%\n", percentage);

    return 0;
}