#include <stdio.h>
#include <stdlib.h>

struct Data {
	int val;
	struct Data *left, *right, *parent;
}*root, *curr, *temp;

struct Data *newNode(struct Data *parent, int val) {
	curr = (struct Data *)malloc(sizeof(struct Data));
	curr->val = val;
	curr->left = curr->right = NULL;
	curr->parent = parent;
	
	return curr;
}

void push(struct Data *curr, int val) {
	if(root == NULL) {
		root = newNode(NULL, val);
	}
	else {
		if(val < curr->val) {
			if(curr->left == NULL) {
				curr->left = newNode(curr, val);
			}
			else {
				push(curr->left, val);
			}
		}
		else if(val > curr->val) {
			if(curr->right == NULL) {
				curr->right = newNode(curr, val);
			}
			else {
				push(curr->right, val);
			}
		}
	}
}

void preOrder(struct Data *curr) {
	if(curr) {
		printf("%d ", curr->val);
		preOrder(curr->left);
		preOrder(curr->right);
	}
}

void inOrder(struct Data *curr) {
	if(curr) {
		inOrder(curr->left);
		printf("%d ", curr->val);
		inOrder(curr->right);
	}
}

void postOrder(struct Data *curr) {
	if(curr) {
		postOrder(curr->left);
		postOrder(curr->right);
		printf("%d ", curr->val);
	}
}

void displayAll() {
	printf("Preorder : "); preOrder(root); puts("");
	printf("inorder : "); inOrder(root); puts("");
	printf("Postorder : "); postOrder(root); puts("");
}

void menu1() {
	int val;
	do {
		printf("Add: Input Number [0..99]: ");
		scanf("%d", &val); getchar();
	} while(val < 0 || val > 99);
	
	push(root, val);
}

struct Data *predecessor(struct Data *curr) {
	curr = curr->left;
	while(curr->right) {
		curr = curr->right;
	}
	return curr;
}

void pop(struct Data *curr, int val) {
	if(curr == NULL) {
		return;
	}
	if(val < curr->val) {
		pop(curr->left, val);
	}
	else if(val > curr->val) {
		pop(curr->right, val);
	}
	else {
		if(curr->left == NULL && curr->right == NULL) {
			if(curr == root) {
				root = NULL;
			}
			else if(curr == curr->parent->left) {
				curr->parent->left = NULL;
			}
			else if(curr == curr->parent->right) {
				curr->parent->right = NULL;
			}
			free(curr);
			curr = NULL;
		}
		else if(curr->left == NULL || curr->right == NULL) {
			temp = (curr->left)?curr->left:curr->right;
			struct Data *parent = curr->parent;
			*curr = *temp;
			curr->parent = parent;
		}
		else {
			temp = predecessor(curr);
			curr->val = temp->val;
			pop(curr->left, temp->val);
		}
	}
}

void menu2() {
	int val;
	do {
		printf("Add: Input Number [0..99]: ");
		scanf("%d", &val); getchar();
	} while(val < 0 || val > 99);
	
	pop(root, val);
}

int main() {
	push(root, 10);
	push(root, 5);
	push(root, 7);
	push(root, 15);
	push(root, 20);
	push(root, 17);
	
	int pilih;
	do {
		system("cls");
		displayAll();
		puts("\n\n");
		printf("BST\n");
		printf("===\n\n");
		printf("1. Add New Number\n");
		printf("2. Remove Number\n");
		printf("3. Search Number\n");
		printf("0. Exit and Popall\n");
		
		printf("Input : ");
		scanf("%d", &pilih);
		switch(pilih) {
			case 1:	menu1(); break;
			case 2: menu2(); break;
			case 3: break;
		}
	} while(pilih != 0);
	
	return 0;
}
