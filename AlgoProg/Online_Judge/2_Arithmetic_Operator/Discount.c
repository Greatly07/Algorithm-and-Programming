#include <stdio.h>

int main()
{
    float initPrice, CurrPrice;
    scanf("%f %f", &initPrice, &CurrPrice);

    float discount = ((initPrice - CurrPrice) / initPrice) * 100;

    printf("%.2f%%\n", discount);

    return 0;
}