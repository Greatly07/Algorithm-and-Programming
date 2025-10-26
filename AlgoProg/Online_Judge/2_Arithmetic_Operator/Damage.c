#include <stdio.h>

int main()
{
    float physDmg, magiDmg, pureDmg;
    scanf("%f %f %f", &physDmg, &magiDmg, &pureDmg);

    float totalDmg = (physDmg * 0.2) + (magiDmg * 0.3) + (pureDmg * 0.5);
    printf("%.2f\n", totalDmg);

    return 0;
}