#include <stdio.h>

int main()
{
    int arr[100];
    int i = 0;
    scanf("%d", &arr[i]);

    while (arr[i] >= 0)
    {
        if (i > 9)
        {
            printf("Too many numbers\n");
            return 0;
        }

        i++;
        scanf("%d", &arr[i]);
    }

    i /= 2;
    printf("Middle item: %d\n", arr[i]);

    return 0;
}