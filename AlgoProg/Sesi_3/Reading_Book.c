#include <stdio.h>

int main()
{
    int testCase;
    scanf("%d", &testCase);

    for (int i = 1; i <= testCase; i++)
    {
        long long int totalPage, pageToGo;
        scanf("%lld %lld", &totalPage, &pageToGo);

        long long int flip_front = pageToGo / 2;
        long long int flip_back = totalPage / 2 - pageToGo / 2;

        if (flip_front < flip_back)
        {
            printf("Case #%d: %lld\n", i, flip_front);
        }
        else
        {
            printf("Case #%d: %lld\n", i, flip_back);
        }
    }
    return 0;
}