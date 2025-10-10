#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int n;
        long long int k;
        scanf("%d %lld", &n, &k);

        char str[n + 1];
        scanf("%s", str);

        k = k % 26;

        for (int i = 0; i < n; i++)
        {
            str[i] = ((str[i] - 'a' + k) % 26) + 'a';
        }
        printf("Case #%d: %s\n", t, str);
    }

    return 0;
}