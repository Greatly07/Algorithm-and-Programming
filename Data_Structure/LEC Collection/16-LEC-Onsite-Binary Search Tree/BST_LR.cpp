#include<stdio.h>
#include<stdlib.h> 

struct Node{
	int val;
	struct Node *left;
	struct Node *right;
}*root, *curr, *temp;

//anak paling kiri dari subtree kanan
//left most child of its right sub tree 
struct Node *successor(struct Node *curr){
	curr = curr->right;
	while(curr->left){
		curr = curr->left;
	} 
	return curr;
}

//anak paling kanan dari subtree kiri
//right most child of its left sub tree 
struct Node *predecessor(struct Node *curr){
	curr = curr->left;
	while(curr->right){
		curr = curr->right;
	}
	return curr;
}

struct Node *newNode(int val){
	struct Node *curr = (struct Node*) malloc(sizeof(struct Node));
	curr->val = val;
	curr->left = curr->right = NULL;
	return curr;
}

struct Node * insert(struct Node *curr, int value){
	if(curr == NULL) return newNode(value);
	else if(value < curr->val){
		curr->left = insert(curr->left, value);
	}else{
		curr->right = insert(curr->right, value);
	}
}

struct Node *pop(struct Node *curr, int value){
	if(curr == NULL) return NULL; // tidak ketemu
	if(value < curr->val){
		curr->left = pop(curr->left, value);
	}else if(value > curr->val){
		curr->right = pop(curr->right, value);
	}else{ //found, delete
		// case 1 - leaf (no child)
		// case 2 - only have left child
		// case 3 - only have right child
		// case 4 - have left and right child, find predecessor* / successor
		// *in our class, we choose this
		
		temp = NULL;
		//if curr has 1 child (left only/right only) : temp is the left / right child of curr
		//if curr has 2 child : temp is predecessor : right most child of its left sub tree 
		
		// case 1 - leaf (no child)
		if(!curr->left && !curr->right) { // no child
			if(curr==root) root = NULL;
			
			free(curr);
			curr = NULL;
		}	
		// case 2 - only have left child
		// case 3 - only have right child
		else if(curr->left == NULL || curr->right == NULL){			
			if(curr->left) temp = curr->left; // case 2: only have left child
			else temp = curr->right;// case 3 - only have right child
			
			*curr= *temp; //set the value from pointer temp's address as the value of pointer temp's address
		}
		else {
			//case 4 - have left and right child, find predecessor	
			
			temp = predecessor(curr);
			curr->val = temp->val;
			//delete
			curr->left = pop(curr->left, temp->val);	
		}
	}
	return curr;
}

void displayAll(struct Node *curr){ // inorder
	if(curr) 
	{
		displayAll(curr->left);
		printf("%d ", curr->val);
		displayAll(curr->right);	
	}
}

struct Node *popAll(struct Node *curr){
	if(curr)
	{
		curr->left = popAll(curr->left);
		curr->right = popAll(curr->right);
		free(curr);	
	}
	return NULL;
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
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 7);
	root = insert(root, 15);
	root = insert(root, 20);
	root = insert(root, 17);
	displayAll(root);
	//5 7 10 15 17 20
	puts("");
	
	root = pop(root, 10);
	displayAll(root);
	puts("");
	
	root = pop(root, 15);
	displayAll(root);
	puts("");	

	root = pop(root, 20);
	displayAll(root);
	puts("");	
	
	root = pop(root, 5);
	displayAll(root);
	puts("");	

	root = pop(root, 7);
	displayAll(root);
	puts("");	
	
	root = pop(root, 17);
	displayAll(root);
	puts("");	
	
		
	root = popAll(root);
	displayAll(root);
	puts("");	
	
	return 0;
}
