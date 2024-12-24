#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS 

struct node {
	int item;
	node* right;
	node* left;
};

void delete_from_left(node** root) {
	if ((*root)->left ==NULL)
	{
		free(*root);
		(*root)=NULL;
		return;
	}
	delete_from_left(&(*root)->left);
}

void insert(node** root, int item) {
	if (*root==NULL)
	{
		*root = (struct node*)malloc(sizeof(struct node));
		(*root)->item = item;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if (item<(*root)->item) {
		insert(&(*root)->left,item);
	}
	else if (item > (*root)->item) {
		insert(&(*root)->right, item);
	}
}
void inorder(node* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->item);
		inorder(root->right);
	}
}
int main() {
	node* root= NULL;

	insert(&root, 50);
	insert(&root, 30);
	insert(&root, 20);
	insert(&root, 40);
	insert(&root, 70);
	insert(&root, 60);
	insert(&root, 80);
	insert(&root, 100);
	insert(&root, 90);
	inorder(root);
	printf("\n");
	delete_from_left(&root);
	inorder(root);
}
