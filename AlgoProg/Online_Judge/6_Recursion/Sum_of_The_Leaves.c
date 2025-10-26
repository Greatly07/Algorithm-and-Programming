#include <stdio.h>

void leaveSum(int n, int tree[], int index, int sum)
{
    int result = sum + tree[index];

    int leftLeaf = (index * 2) + 1;
    int rightLeaf = (index * 2) + 2;

    if (leftLeaf >= n && rightLeaf >= n)
    {
        printf("%d\n", result);
        return;
    }

    if (leftLeaf < n)
    {
        leaveSum(n, tree, leftLeaf, result);
    }
    if (rightLeaf < n)
    {
        leaveSum(n, tree, rightLeaf, result);
    }
}

int main()
{
    int testCases;
    scanf("%d", &testCases);

    for (int t = 1; t <= testCases; t++)
    {
        int n;
        scanf("%d", &n);

        int tree[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tree[i]);
        }

        printf("Case #%d:\n", t);
        leaveSum(n, tree, 0, 0);
    }

    return 0;
}