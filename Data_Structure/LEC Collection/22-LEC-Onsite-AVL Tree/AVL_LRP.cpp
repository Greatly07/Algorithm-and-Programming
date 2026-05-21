#include<stdio.h>
#include<stdlib.h>

struct Data{
	int value;
	int height;
	struct Data *left, *right, *parent;
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
	if(curr == NULL) return 0;	
	return getHeight(curr->left) - getHeight(curr->right);
}

void fixParent(struct Data *curr, struct Data *parent)
{
	if(curr)
	{
		fixParent(curr->left, curr); // fix left subtree nodes curr-parent relationship
		fixParent(curr->right, curr); // fix right subtree nodes curr-parent relationship
		curr->parent = parent; // fix every curr nodes traversed
	}
}

void fixHeight(struct Data *curr)
{
	if(curr)
	{
		fixParent(curr->left, curr); // fix left subtree nodes curr-parent relationship
		fixParent(curr->right, curr); // fix right subtree nodes curr-parent relationship
		curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
	}
}

struct Data *rightRotate(struct Data *y){
	//anggap y paling atas/root. 
	//anak kiri y => x. subtree kiri x=> A, subtree kanan x=>B.
	//subtree kanan y => c
	//				y
	//		[x]				c
	//	a		[b]
	struct Data *parent = y->parent;
	struct Data *x = y->left;
	struct Data *b = x->right;
		
	//rotate
	x->right = y;
	y->left = b;
	
	//
	//				x
	//		a				[y]
	//					[b]		c
	
	//hitung height ulang
	//dari bawah c, (y) dilanjutkan x. agar saat hitung x, nilai y udah ke update	
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	fixParent(x, parent);
	fixHeight(x);
	//return x yang menjadi Data paling atas 
	return x; 	
}

struct Data *leftRotate(struct Data *x){
	struct Data *parent = x->parent;
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
	fixParent(y, parent);
	fixHeight(y);
	return y;
}

//anak paling kecil dari subtree kanan
struct Data *successor(struct Data *root){
	struct Data *curr = root->right;
	while(curr->left != NULL){
		curr = curr->left;
	} 
	return curr;
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
	curr->left = NULL;
	curr->right = NULL;
	curr->parent = NULL;
	return curr;
}

struct Data * rebalance(struct Data *curr, int value)
{
	curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
	int balanceFactor = getBalanceFactor(curr);
	int balanceFactorLeft = getBalanceFactor(curr->left);
	int balanceFactorRight = getBalanceFactor(curr->right);
	
	if(balanceFactor > 1 && balanceFactorLeft >= 0){ // LL
		return rightRotate(curr);
	}
	if(balanceFactor > 1 && balanceFactorLeft < 0){ // LR
		curr->left = leftRotate(curr->left);
		return rightRotate(curr);
	}
	if(balanceFactor < -1 && balanceFactorRight <= 0){ // RR
		return leftRotate(curr);
	}
	if(balanceFactor < -1 && balanceFactorRight > 0){ // RL
		curr->right = rightRotate(curr->right);
		return leftRotate(curr);
	}
	return curr;
}

struct Data *push(struct Data *curr, int value){
	int balanceFactor;
	if(curr == NULL) return newNode(value);
	
	
	if (value < curr->value)
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
				free(curr);
				curr = NULL;
			}else{
				struct Data *parent = curr->parent;
				// case 2 & 3
				*curr = *temp; //copy isinya
				curr->parent = parent;
				fixParent(curr, curr->parent); 	
				free(temp);
			}
		
		}else{
		//case 4: punya 2 anak, cari predecessor / successor
			
			temp = predecessor(curr);
			curr->value = temp->value;
			//delete
			curr->left = pop(curr->left, temp->value);	
		}
	}
	
	//case 1, tidak perlu fix height and rebalance
	if(curr == NULL) return NULL; 	
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
		printf("height : %d\n", curr->height);
		
		if(curr == root)
		{
			printf("- is a root\n", curr->value);		
		}
		else if (curr->left == NULL && curr->right == NULL) printf("- is an external node(leaf)\n");
		else printf("- is an internal node\n");
		
		if(curr->parent) printf("- parent : %d\n", curr->parent->value);
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
	struct Data *root = NULL;
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
	return 0;
}
