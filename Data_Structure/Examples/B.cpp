#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	int *arr = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i = 0; i < k; i++){
		int temp = *(arr+n-1);
		
		for(int j = n-1; j > 0; j--){
			*(arr+j) = *(arr+j-1); 
		}
		
		*arr = temp;
	}
	
	for(int i = 0; i < n; i++){
		printf("%d ", *(arr+i));
	}
	
	return 0;
	
}
