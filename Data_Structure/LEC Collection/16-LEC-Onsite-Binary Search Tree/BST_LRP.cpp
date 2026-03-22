#include<stdio.h>
#include<stdlib.h>

struct Data{
	int val;
	struct Data *left, *right, *parent;
}*root, *curr;

//anak paling kiri dari subtree kanan
//left most child of its right sub tree 
struct Data *successor(struct Data *curr) {
	curr = curr->right;
	while(curr->left)
	{
		curr = curr->left;
	} 
	return curr;
}

//anak paling kanan dari subtree kiri
//right most child of its left sub tree 
struct Data *predecessor(struct Data *curr){
	curr = curr->left;
	while(curr->right)
	{
		curr = curr->right;
	}
	return curr;
}

struct Data *newNode(struct Data *parent, int val){
	curr = (struct Data*)malloc(sizeof(struct Data));
	curr->val = val;
	curr->left = curr->right = NULL;
	curr->parent = parent;
	return curr;
}

void push(struct Data *curr, int val){
	if(root == NULL) // first data
	{
		root = newNode(NULL, val);
	}
	else // not the first data
	{
		if(val < curr->val)
		{
			if( curr->left == NULL )
			{
				curr->left = newNode(curr, val);
			}
			else
			{
				push(curr->left, val);
			}
		}
		else if (val > curr->val)
		{
			if( curr->right == NULL )
			{
				curr->right = newNode(curr, val);
			}
			else
			{
				push(curr->right, val);
			}
		}		
	}
}

void pop(struct Data *curr, int val){
	if(curr == NULL) return;
	
	if(val < curr->val){
		pop(curr->left, val);
	}else if(val > curr->val){
		pop(curr->right, val);
	}else{ // found, delete
		// case 1 - leaf (no child)
		// case 2 - only have left child
		// case 3 - only have right child
		// case 4 - have left and right child, find predecessor* / successor
		// *in our class, we choose this
		
		// case 1 - leaf (no child)
		if(!curr->left && !curr->right) // kiri kanan NULL
		{
			//If the key is in a leaf, just delete that node
			
			// data yg mau dihapus adl NULL
			if(curr==root) root = NULL;			
			else if (curr->parent->left == curr ) curr->parent->left = NULL;			
			else if (curr->parent->right == curr ) curr->parent->right = NULL;

			free(curr);
		}
		// case 2 - only have left child
		// case 3 - only have right child
		else if( !curr->left  || !curr->right ){ // kiri NULL atau kanan NULL
			struct Data *temp;
	
			temp = (curr->left)?curr->left:curr->right;	
			
			//before 
			//*curr = *temp; //copy isi
			
			//after 					
			struct Data *parent = curr->parent;
			
			*curr = *temp;
			
			curr->parent = parent;
			free(temp);
		}else{ 
			//case 4 - have left and right child, find predecessor	
			struct Data *temp = predecessor(curr);
			curr->val = temp->val;
			//delete
			pop(curr->left, temp->val);
		}
	}
}

void popAll(struct Data *curr)
{
	if(curr)
	{
		popAll(curr->left);
		popAll(curr->right);
		free(curr);
	}
	root = NULL;
}

void menu()
{
	printf("\n BST");
	printf("\n ===\n");
	printf("\n 1. Add New Number");
	printf("\n 2. Remove Number");
	printf("\n 3. Search Number");
	printf("\n 0. Exit and Popall");
	printf("\n Input : ");
}

void inOrder(struct Data *curr)
{
	if(curr)
	{
		inOrder(curr->left);
		printf("%d ",curr->val);
		inOrder(curr->right);
	}
}

void preOrder(struct Data *curr)
{
	if(curr)
	{
		printf("%d ",curr->val);
		preOrder(curr->left);		
		preOrder(curr->right);
	}
}

void postOrder(struct Data *curr)
{
	if(curr)
	{
		postOrder(curr->left);
		postOrder(curr->right);
		printf("%d ",curr->val);
	}
}

void inprepost()
{
	if(root)
	{
		printf("\n Preorder  : ");
		preOrder(root);
		printf("\n Inorder   : ");
		inOrder(root);
		printf("\n Postorder : ");
		postOrder(root);
		printf("\n\n\n");
	}
}

struct Data * find (struct Data * curr, int val) // recursion
{ 
	if ( curr == NULL ) return NULL;

	// x is found
	else if ( val == curr->val ) return curr;
	else if ( val  < curr->val ) return find(curr->left, val); // val is located in left sub tree
	else return find(curr->right, val); // val is located in right sub tree
}

void menu1()
{
	int val;
	printf("\n\n\n");
	do
	{
		printf("Add: Input Number [0..99]: ");
		scanf("%d", &val); getchar();
	}while(val<0 || val>99);
	push(root, val);

}

void menu2()
{
	int val;
	printf("\n\n\n");
	do
	{
		printf("Remove: Input Number [0..99]: ");
		scanf("%d", &val);
		getchar();
	}while(val<0 || val>99);
	pop(root, val);
}

void menu3()
{
	struct Data *curr;
	int val;

	printf("\n\n\n");
	do
	{
		printf("Find: Input Number [0..99]: ");
		scanf("%d", &val);
		getchar();
	}while(val<0 || val>99);

	curr = find(root, val);
	if(curr)
	{
		printf("%d is found.\n", curr->val);
		if(curr == root)
		{
			printf("- is a root\n", curr->val);		
		}
		else if (curr->left == NULL && curr->right == NULL) printf("- is an external node(leaf)\n");
		else printf("- is an internal node\n");
		
		if(curr->parent) printf("- parent : %d\n", curr->parent->val);
		if(curr->left) printf("- left :  %d\n", curr->left->val);
		if(curr->right) printf("- right :  %d\n", curr->right->val);
		// add here
		printf ("\n");
		
	}
	else
	{
		printf("%d is not found.\n", val);
	}
	printf("Press Enter to Continue ... \n");
	getchar();
}

/*
					[10]
		5					15
				7						20
									17

pop 10	: case 4 - have left and right child, find predecessor	
					7
		5					[15]
										20
									17
pop 15 : case 3 - only have right child
					7
		5					[20]
						17 
pop 20 : case 2 - only have left child
					7
		[5]					17
pop 5 : case 1 - leaf
					7
							17
*/

int main(){
	int pilih;
	push(root, 10);
	push(root, 5);
	push(root, 7);
	push(root, 15);
	push(root, 20);
	push(root, 17);	 
	//popAll(root);
	do
	{
		system("cls");
		inprepost();
		menu();
		scanf("%d", &pilih); getchar();

		switch(pilih)
		{
			case 1 : menu1(); break;
			case 2 : menu2(); break;			
			case 3 : menu3(); break;

		}

	} while(pilih!=0);

	popAll(root);
	return 0;
}
