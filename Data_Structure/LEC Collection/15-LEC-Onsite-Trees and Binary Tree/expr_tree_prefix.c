/**
 * Implementasi expression tree untuk input berupa prefix
 * 
 * Program ini melakukan parsing notasi matematika berupa prefix menjadi 
 * sebuah expression tree.
 * 
 * Untuk program ini setiap bilangan dibatasi hanya 1 digit.
 * 
 * Contoh prefix: *+12/-345
 * 
 * Hasilnya:
 *              [*]
 *           /---|--\
 *          [+]     [/]
 *          / \     / \
 *        [1] [2] [-] [5]
 *                / \
 *              [3] [4]
 * 
 * Note : Coba buat versi lain dari program ini untuk melakukan parsing 
 *        dari notasi postfix.
 * 
 * Author : Fajar Chandra <D4855>
 * Date   : 2013.03.22
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char val;
    struct Node *left;
    struct Node *right;
};

struct Node *root;

// Mencetak secara prefix
/* Aturan traverse prefix:
 * 1. cetak node
 * 2. telusuri ke kiri
 * 3. telusuri ke kanan
 */
void prefix(struct Node *node) {
    if(node == NULL)
        return;
    printf("%c ", node->val);
    prefix(node->left);
    prefix(node->right);
}

// Mencetak secara infix
/* Aturan traverse infix:
 * 1. telusuri ke kiri
 * 2. cetak
 * 3. telusuri ke kanan
 */
void infix(struct Node *node) {
    if(node == NULL)
        return;
        
    if(node->left != NULL)
        printf("( ");
    infix(node->left);
    printf("%c ", node->val);
    infix(node->right);
    if(node->left != NULL)
        printf(") ");
}

// Mencetak secara postfix
/* Aturan traverse prefix:
 * 1. telusuri ke kiri
 * 2. telusuri ke kanan
 * 3. cetak node
 */
void postfix(struct Node *node) {
    if(node == NULL)
        return;
    postfix(node->left);
    postfix(node->right);
    printf("%c ", node->val);
}

// Menghapus node serta semua anak-anak (descendants / subtree) di bawahnya
/* Teknik menghapus sama seperti postfix */
void delete_rec(struct Node **node) {
    if(*node == NULL)
        return;
        
    delete_rec(&(*node)->left);
    delete_rec(&(*node)->right);
    
    free(*node);
    *node = NULL;
}

// Membuat node baru
struct Node * new_node(char val) {
    // Buat node
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    
    return node;
}

// Lakukan parsing notasi menjadi tree
// Return: index sisa string
int parse(struct Node **node, char prefix[], int i) { // parse(&root, "*+12/-345", 0) 
	if(!isdigit(prefix[i])) {										// 012345678		
	        (*node) = new_node(prefix[i]); // [0] new_node('*'); [1] new_node('+');  [4] new_node('/'); [5] new_node('-'); 
        i = parse(&(*node)->left, prefix, ++i); // [0-1] + anak kiri *  i = parse(&(*node)->left, "*+12/-345", 2); [2] 1 anak kiri + dst
													
        i = parse(&(*node)->right, prefix, i); // [0-2, dilakukan setelah 3] / anak kanan * i = parse(&(*node)->right, "*+12/-345", 3); [3] 2 anak kanan +
        
        return i; 
    }
    else {
        (*node) = new_node(prefix[i]);
        return i+1; 
    }
}

int main() {
    parse(&root, "*+12/-345", 0);
    
    printf("Prefix : ");
    prefix(root);
    printf("\n");
    
    printf("Infix : ");
    infix(root);
    printf("\n");
    
    printf("Postfix : ");
    postfix(root);
    printf("\n");
    getchar();
    
    delete_rec(&root); // Jangan lupa memori dibersihkan
    return 0;
}
