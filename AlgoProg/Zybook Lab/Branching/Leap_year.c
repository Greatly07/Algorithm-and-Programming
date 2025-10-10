#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int inputYear;
    bool isLeapYear = false;

    scanf("%d", &inputYear);
    if (inputYear % 400 == 0)
    {
        isLeapYear = true;
    }
    else if (inputYear % 100 == 0)
    {
        isLeapYear = false;
    }
    else if (inputYear % 4 == 0)
    {
        isLeapYear = true;
    }
    else
    {
        isLeapYear = false;
    }
    if (isLeapYear)
    {
        printf("%d - leap year\n", inputYear);
    }
    else
    {
        printf("%d - not a leap year\n", inputYear);
    }

    return 0;
}