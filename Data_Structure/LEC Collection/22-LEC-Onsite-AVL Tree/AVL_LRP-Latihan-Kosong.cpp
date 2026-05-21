#include<stdio.h>
#include<stdlib.h>

struct Data{
	int value;
	int height;
	struct Data *left, *right, *parent;
};

int max(int a, int b)
{
	return 0;
}

int getHeight(struct Data* curr)
{
	return 0;
}

int getBalanceFactor(struct Data *curr)
{
	return 0;
}

void fixParent(struct Data *curr, struct Data *parent)
{
	if(curr)
	{
		// fix left subtree nodes curr-parent relationship
		// fix right subtree nodes curr-parent relationship
		// fix every curr nodes traversed
	}
}

void fixHeight(struct Data *curr)
{
	if(curr)
	{
		
	}
}
struct Data *rightRotate(struct Data *y){
	//anggap y paling atas/root. 
	//anak kiri y => x. subtree kiri x=> A, subtree kanan x=>B.
	//subtree kanan y => c
	//				y
	//		[x]				c
	//	a		[b]

	
	//rotate
	
	
	//
	//				x
	//		a				[y]
	//					[b]		c
	
	//hitung height ulang
	//dari bawah (y) dilanjutkan x. agar saat hitung x, nilai y udah ke update

	//return x yang menjadi Data paling atas 
	return 0; 	
}

struct Data *leftRotate(struct Data *x){

	
	//				x
	//		a				[y]
	//					[b]		c	
	
	//rotate


	//				y
	//		[x]				c
	//	a		[b]					
	

	return 0;
}

//anak paling kecil dari subtree kanan
struct Data *successor(struct Data *root){

	return 0;
}

//anak paling kanan dari subtree kiri
struct Data *predecessor(struct Data *root){

	return 0;
}

struct Data *newNode(int x){
	
	return 0;
}

struct Data * rebalance(struct Data *curr)
{
	return 0;
}

struct Data *push(struct Data *curr, int value){

	return 0;
}

struct Data *pop(struct Data *curr, int value){
	//tidak ketemu
	
	//ketemu, delete
		// case 1: tidak punya anak
		// case 2: hanya punya anak kiri
		// case 3: hanya punya anak kanan	
		//case 4: punya 2 anak, cari predecessor / successor
		
		
	//case 1, tidak perlu fix height and rebalance
	
	//case 2-4, perlu fix height and rebalance
	return 0;
}

void printAll(struct Data *curr){
	
}

struct Data *popAll(struct Data *curr){
	
	return 0;
}

struct Data * find (struct Data * curr, int value) // recursion
{ 
	

	// x is found
	// val is located in left sub tree
	// val is located in right sub tree
	return 0;
}


void searchDisplay(struct Data *root, int value)
{


}


int main(){
	struct Data *root = NULL;
/*
	root = push(root, 60);
	root = push(root, 65);
	root = push(root, 25);
	root = push(root, 50);
	root = push(root, 55);//RR
	root = push(root, 40);//LL
	root = push(root, 30);//RL
	root = push(root, 15);
	root = push(root, 20);//LR
	
	printAll(root);
	puts("");
	
	root = pop(root, 15);
	printAll(root);
	puts("");
	
	root = pop(root, 50); //LR
	printAll(root);
	puts("");	
	
	root = pop(root, 65); 
	printAll(root);
	puts("");	
	
	root = pop(root, 25); 
	printAll(root);
	puts("");	
	
	root = pop(root, 20); 
	printAll(root);
	puts("");	
	
	root = pop(root, 30); //RL
	printAll(root);
	puts("");	
		
	int x;
	do
	{
		scanf("%d", &x);
		searchDisplay(root, x);
	} while (x!=0);		

	root = popAll(root);
*/	return 0;
}
