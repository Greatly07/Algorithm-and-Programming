#include <stdio.h>

int main(void)
{
    int highwayNumber;
    scanf("%d", &highwayNumber);

    if (highwayNumber % 100 == 0 || highwayNumber < 1 || highwayNumber > 999)
    {
        printf("%d is not a valid interstate highway number.\n", highwayNumber);
    }
    else if (highwayNumber > 100)
    {
        printf("I-%d is auxiliary, serving I-%d, going ", highwayNumber, highwayNumber % 100);
        if (highwayNumber % 2 == 0)
        {
            printf("east/west.\n");
        }
        else
        {
            printf("north/south.\n");
        }
    }
    else if (highwayNumber >= 1 && highwayNumber <= 99)
    {
        printf("I-%d is primary, going ", highwayNumber);
        if (highwayNumber % 2 == 0)
        {
            printf("east/west.\n");
        }
        else
        {
            printf("north/south.\n");
        }
    }

    return 0;
}