#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr, int x, int y)
{
	while(x < y)
	{
		int temp = *(arr + x);
		*(arr + x) = *(arr + y);
		*(arr + y) = temp;
		
		x++;
		y--;
	}
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	int *arr = (int *)malloc(n * sizeof(int));
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
	}
	
	reverse(arr, 0, n - 1);
	reverse(arr, k, n - 1);
	reverse(arr, 0, k - 1);
	
	int firstprint = 1;
	for(int i = 0; i < n; i++)
	{
		if(firstprint)
		{
			printf("%d", *(arr + i));
			firstprint = 0;
		}
		else
		{
			printf(" %d", *(arr + i));
		}
	}
	printf("\n");

	free(arr);	
	return 0;
}
