#include <stdio.h>
#include <string.h>

int main(void)
{
    char inputMonth[50];
    int inputDay;

    scanf("%s", inputMonth);
    scanf("%d", &inputDay);

    if ((strcmp(inputMonth, "March") == 0 && inputDay >= 20 && inputDay <= 31) ||
        (strcmp(inputMonth, "April") == 0 && inputDay >= 1 && inputDay <= 30) ||
        (strcmp(inputMonth, "May") == 0 && inputDay >= 1 && inputDay <= 31) ||
        (strcmp(inputMonth, "June") == 0 && inputDay >= 1 && inputDay <= 20))
    {
        printf("Spring\n");
    }
    else if ((strcmp(inputMonth, "June") == 0 && inputDay >= 21 && inputDay <= 30) ||
             (strcmp(inputMonth, "July") == 0 && inputDay >= 1 && inputDay <= 31) ||
             (strcmp(inputMonth, "August") == 0 && inputDay >= 1 && inputDay <= 31) ||
             (strcmp(inputMonth, "September") == 0 && inputDay >= 1 && inputDay <= 21))
    {
        printf("Summer\n");
    }
    else if ((strcmp(inputMonth, "September") == 0 && inputDay >= 22 && inputDay <= 30) ||
             (strcmp(inputMonth, "October") == 0 && inputDay >= 1 && inputDay <= 31) ||
             (strcmp(inputMonth, "November") == 0 && inputDay >= 1 && inputDay <= 30) ||
             (strcmp(inputMonth, "December") == 0 && inputDay >= 1 && inputDay <= 20))
    {
        printf("Autumn\n");
    }
    else if ((strcmp(inputMonth, "December") == 0 && inputDay >= 21 && inputDay <= 31) ||
             (strcmp(inputMonth, "January") == 0 && inputDay >= 1 && inputDay <= 31) ||
             (strcmp(inputMonth, "February") == 0 && inputDay >= 1 && inputDay <= 29) ||
             (strcmp(inputMonth, "March") == 0 && inputDay >= 1 && inputDay <= 19))
    {
        printf("Winter\n");
    }
    else
    {
        printf("Invalid\n");
    }

    return 0;
}