#include<stdio.h>
#include<stdlib.h>

struct Data{
	int value;
	int height;
	struct Data *left, *right;
};

int max(int a, int b)
{
	return (a>b)?a:b;
}

int getHeight(struct Data* curr)
{
	if(curr == NULL) return 0;
	return curr->height;
}

int getBalanceFactor(struct Data *curr)
{
	// lengkapi
	return 0;
}

struct Data *rightRotate(struct Data *y){
	//Lengkapi
	
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
	struct Data *y = x->right;
	struct Data *b = y->left;
	
	//				x
	//		a				[y]
	//					[b]		c	
	
	//rotate
	y->left = x;
	x->right = b;

	//				y
	//		[x]				c
	//	a		[b]					
	
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	
	return y;
}

//anak paling kecil dari subtree kanan
struct Data *successor(struct Data *root){
	struct Data *cur = root->right;
	while(cur->left != NULL){
		cur = cur->left;
	} 
	return cur;
}

//anak paling kanan dari subtree kiri
struct Data *predecessor(struct Data *root){
	struct Data *cur = root->left;
	while(cur->right != NULL){
		cur = cur->right;
	}
	return cur;
}

struct Data *newNode(int x){
	struct Data *curr = (struct Data*)malloc(sizeof(struct Data));
	curr->value = x;
	curr->height = 1;
	curr->left = curr->right = NULL;
	return curr;
}

struct Data * rebalance(struct Data *curr, int value)
{
	curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
	int balanceFactor = getBalanceFactor(curr);
	int balanceFactorLeft = getBalanceFactor(curr->left);
	int balanceFactorRight = getBalanceFactor(curr->right);
	
	if(balanceFactor > 1 && balanceFactorLeft >= 0){ // LL
		printf("LL : RightRotate(%d)\n", curr->value);
		
		return rightRotate(curr);
	}
	if(balanceFactor > 1 && balanceFactorLeft < 0){ // LR
		printf("LR : \n");
		printf("LeftRotate(%d)\n", curr->left->value);
		printf("RightRotate(%d)\n", curr->value);
		
		curr->left = leftRotate(curr->left);
		return rightRotate(curr);
	}
	if(balanceFactor < -1 && balanceFactorRight <= 0){ // RR
		printf("RR : LeftRotate(%d)\n", curr->value);
	
		return leftRotate(curr);
	}
	if(balanceFactor < -1 && balanceFactorRight > 0){ // RL
		printf("RL : \n");
		printf("RightRotate(%d)\n", curr->right->value);
		printf("LeftRotate(%d)\n", curr->value);
	
		curr->right = rightRotate(curr->right);
		return leftRotate(curr);
	}
	return curr;
}

struct Data *push(struct Data *curr, int value){
	int balanceFactor;
	if(curr == NULL) return newNode(value);
	else if (value < curr->value)
	{
		curr->left = push(curr->left, value);
	}
	else{
		curr->right = push(curr->right, value);
	}
	
	return rebalance(curr, value);
}

struct Data *pop(struct Data *curr, int value){
	struct Data *temp;
	if(curr == NULL) return NULL; //tidak ketemu
	if(value < curr->value){
		curr->left = pop(curr->left, value);
	}else if(value > curr->value){
		curr->right = pop(curr->right, value);
	}else{ //ketemu, delete
		// case 1: tidak punya anak
		// case 2: hanya punya anak kiri
		// case 3: hanya punya anak kanan	
		if(curr->left == NULL || curr->right == NULL){
			
			temp = (curr->left != NULL)? curr->left : curr->right;
			
			if(temp == NULL){
				//tidak punya anak (case 1)
				temp = curr;
				curr = NULL;
			}else{
				// case 2 & 3
				*curr = *temp; //copy isinya
			}
			free(temp);
		}else{
		//case 4: punya 2 anak, cari predecessor / successor
			
			temp = predecessor(curr);
			curr->value = temp->value;
			//delete
			curr->left = pop(curr->left, temp->value);	
		}
	}
	
	//case 1, tidak perlu fix height and rebalance
	if(curr == NULL) return curr; 	
	//case 2-4, perlu fix height and rebalance
	return rebalance(curr, value);
}

void printAll(struct Data *curr){
	if(curr == NULL) return;
	printAll(curr->left);
	printf(" %d ", curr->value);
	printAll(curr->right);
}

struct Data *popAll(struct Data *curr){
	if(curr == NULL) return NULL;
	curr->left = popAll(curr->left);
	curr->right = popAll(curr->right);
	free(curr);
	return NULL;
}

struct Data * find (struct Data * curr, int value) // recursion
{ 
	if ( curr == NULL ) return NULL;

	// x is found
	else if ( value == curr->value ) return curr;
	else if ( value  < curr->value ) return find(curr->left, value); // val is located in left sub tree
	else return find(curr->right, value); // val is located in right sub tree
}


void searchDisplay(struct Data *root, int value)
{
	struct Data *curr;

	curr = find(root, value);
	if(curr)
	{
		printf("%d is found.\n", curr->value);
		if(curr == root)
		{
			printf("- is a root\n", curr->value);		
		}
		else if (curr->left == NULL && curr->right == NULL) printf("- is an external node(leaf)\n");
		else printf("- is an internal node\n");
		
		//if(curr->parent) printf("- parent : %d\n", curr->parent->value);
		if(curr->left) printf("- left :  %d\n", curr->left->value);
		if(curr->right) printf("- right :  %d\n", curr->right->value);
		// add here
		printf ("\n");
	}
	else
	{
		printf("%d is not found.\n", value);
	}
	printf("Press Enter to Continue ... \n");
	getchar();
}


int main(){
	int pilih, x;
	struct Data *root = NULL;
	do
	{	
		system("cls");		
		printAll(root);	
		puts("");
		printf("Height of Root : %d\n", getHeight(root));
		printf("AVL\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("0. Exit\n");
		scanf("%d", &pilih); getchar();
		switch(pilih)
		{
			case 1 : 
			{				
				printf("Insert number : ");
				scanf("%d", &x); getchar();
				root = push(root, x);	
			} break;
			case 2 : 
			{
				printf("Delete number : ");
				scanf("%d", &x); getchar();				
				root = pop(root, x);	
			} break;
			case 3 : 
			{
				printf("search number : ");
				scanf("%d", &x); getchar();				
				searchDisplay(root, x);	
			} break;
		}
	} while (pilih != 0);
		
	root = popAll(root);
	return 0;
}
