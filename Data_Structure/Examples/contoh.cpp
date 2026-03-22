#include <stdio.h>

void addDisplay(int x){
	x += 1;
	printf("x : %d\n", x);
}

void addDisplay2(int *x){
	*x += 1;
	printf("x : %d\n", *x);
	
}

void displayArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("[%d]: %d\n", i, arr[i]);
	}
}

void rotateRight(int *arr, int n){
	int temp = arr[n-1];
	for(int i = n-1; i > 0; i--){
		arr[i] = arr[i-1];
	}
	arr[0] = temp;
}

void displayArr2(int *arr, int n){
	for(int i = 0; i < n; i++){
		printf("[%d]: %d\n", i, arr[i]);
	}
}

int main(){
	int x = 10;
	printf("&x: %d\n", &x); // ini address
	printf("x : %d\n", x); // ini nilai
	
	int *px = &x;
	printf("&px : %d\n", &px);
	printf("px : %d\n", px);
	printf("*px : %d\n", *px);
	
	addDisplay(x);
	printf("main-x : %d\n", x);
	addDisplay2(&x);
	printf("main-x : %d\n", x);
	
	int arr[10] = {1,1,1,1,1};
	int arr2[10] = {1,2,3,4,5};
	int n = 5;
	
	printf("arr :\n");
	displayArr(arr, n);
	printf("arr2 :\n");
	displayArr(arr2, n);
	
	rotateRight(arr2, n);
	displayArr2(arr2, n);
	
	return 0;
}
