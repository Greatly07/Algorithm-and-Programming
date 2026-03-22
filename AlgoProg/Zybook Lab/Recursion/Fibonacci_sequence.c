#include <stdio.h>

int Fibonacci(int n)
{
    if (n < 0)
    {
        return -1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int var = Fibonacci(n - 1) + Fibonacci(n - 2);
    return var;
}

int main()
{
    int startNum;
    scanf("%d", &startNum);

    printf("Fibonacci(%d) is %d\n", startNum, Fibonacci(startNum));

    return 0;
}