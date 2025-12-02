#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        int n;
        scanf("%d", &n);

        int time;
        scanf("%d", &time);

        int exQ[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &exQ[i]);
        }

        // Bubble Sort
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (exQ[j] > exQ[j + 1])
                {
                    int temp = exQ[j];
                    exQ[j] = exQ[j + 1];
                    exQ[j + 1] = temp;
                }
            }
        }

        int bestCase = 0;
        int worstCase = 0;
        int tempTime = time;
        int counter = 0;
        while (tempTime > 0 && counter < n)
        {
            if (tempTime - exQ[counter] >= 0)
            {
                bestCase++;
            }
            tempTime -= exQ[counter];
            counter++;
        }

        tempTime = time;
        counter = n - 1;
        while (tempTime > 0 && counter >= 0)
        {
            if (tempTime - exQ[counter] >= 0)
            {
                worstCase++;
            }
            tempTime -= exQ[counter];
            counter--;
        }

        printf("Case #%d: %d %d\n", t, worstCase, bestCase);
    }

    return 0;
}