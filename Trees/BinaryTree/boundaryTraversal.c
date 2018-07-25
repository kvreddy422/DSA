# include<stdio.h>
#include <stdlib.h>
// 1st Print all the Left Nodes, Print all the Right Nodes, Print all the boundary nodes
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

void printBoundaryNodesLeft(struct tree *T){
	if(T && T->left!=NULL || T->right!=NULL){
		printf("%d,",T->data);
		printBoundaryNodesLeft(T->left);	
	}
}

void printChildNodes(struct tree *T){
	if(T){
		if(T->left==NULL && T->right==NULL)
			printf("%d,",T->data);
		printChildNodes(T->left);
		printChildNodes(T->right);
	}
}

void printBoundaryNodesRight(struct tree *T){
	if(T && T->left!=NULL || T->right!=NULL){
		printBoundaryNodesRight(T->right);	
		printf("%d,",T->data);	
	}
}

int main()
{
     struct tree *root  = newNode(20);
     root->left = newNode(8);
     root->right = newNode(22);
     root->left->left = newNode(4);
     root->left->right = newNode(12);
     root->left->right->left = newNode(10);
     root->left->right->right = newNode(14);	 
     root->right->right = newNode(25); 
 
     printf("\nPreorder traversal of binary tree is \n");
     printBoundaryNodesLeft(root);
     printChildNodes(root);	
     if(root->right)	
     printBoundaryNodesRight(root->right);
     getchar();
     return 0;
}
