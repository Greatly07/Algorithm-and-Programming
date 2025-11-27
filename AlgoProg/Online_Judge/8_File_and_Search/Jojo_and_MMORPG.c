#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    long long int level;
    scanf("%lld", &level);

    // Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                long long int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int completedMission = 0;
    for (int i = 0; i < n; i++)
    {
        level -= arr[i];
        if (level >= 0)
        {
            completedMission++;
        }
        else
        {
            break;
        }
    }

    printf("%d\n", completedMission);

    return 0;
}