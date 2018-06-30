# include<stdio.h>
#include <stdlib.h>
// Data , Left and Right
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

// Add a new node
struct tree* newNode(int data){
	struct tree *node = (struct tree*)malloc(sizeof(struct tree));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void printPreorder(struct tree *node){
	if (node==NULL)
		return node;
	printf("%d ",node->data);
	printPreorder(node->left);
	printPreorder(node->right);
}

void printInorder(struct tree *node){
	if (node==NULL)
		return node;
	printInorder(node->left);
	printf("%d ",node->data);	
	printInorder(node->right);
}


void printPostorder(struct tree *node){
	if (node==NULL)
		return node;
	printPostorder(node->left);	
	printPostorder(node->right);
	printf("%d ",node->data);
}


int main()
{
     struct tree *root  = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5); 
 
     printf("\nPreorder traversal of binary tree is \n");
     printPreorder(root);
 
     printf("\nInorder traversal of binary tree is \n");
     printInorder(root);  
 
     printf("\nPostorder traversal of binary tree is \n");
     printPostorder(root);
 
     getchar();
     return 0;
}
