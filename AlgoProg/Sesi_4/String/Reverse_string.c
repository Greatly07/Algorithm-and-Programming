#include <stdio.h>
#include <string.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);
    for (int t = 1; t <= testCases; t++)
    {
        char str[1001];
        scanf("%s", str);

        int len = strlen(str);
        for (int i = 0; i < len / 2; i++)
        {
            char temp = str[i];
            str[i] = str[len - i - 1];
            str[len - i - 1] = temp;
        }
        printf("Case #%d : %s\n", t, str);
    }
    return 0;
}