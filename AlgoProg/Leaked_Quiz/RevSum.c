#include <stdio.h>
#include <string.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        char digits[11];
        scanf(" %s", digits);
        int digLen = strlen(digits);

        long long int number = 0;
        long long int multiply = 1;
        for (int i = 0; i < digLen; i++)
        {
            number += (digits[digLen - 1 - i] - '0') * multiply;
            multiply *= 10;
        }

        long long int revNumber = 0;
        multiply = 1;
        for (int i = 0; i < digLen; i++)
        {
            revNumber += (digits[i] - '0') * multiply;
            multiply *= 10;
        }

        long long int result = number + revNumber;

        printf("Case #%d: %lld\n", t, result);
    }

    return 0;
}