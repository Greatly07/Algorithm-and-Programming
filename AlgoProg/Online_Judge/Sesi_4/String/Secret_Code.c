#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int n;
        char code[1001];
        scanf("%d %s", &n, code);

        for (int i = 0; i < n; i++)
        {
            int L, R;
            scanf("%d %d", &L, &R);

            L--;
            R--;

            while (L < R)
            {
                char temp = code[L];
                code[L] = code[R];
                code[R] = temp;
                L++;
                R--;
            }
        }
        printf("Case #%d: %s\n", t, code);
    }

    return 0;
}