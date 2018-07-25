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
	if(T){
		printf("%d",T->data);
		printBoundaryNodesLeft(T->left);	
	}
}

void printBoundaryNodesRight(struct tree *T){
	if(T){
		printf("%d",T->data);
		printBoundaryNodesRight(T->right);		
	}
}

int main()
{
     struct tree *root  = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5); 
     root->right->left = newNode(6);
     root->right->right = newNode(7); 
 
     printf("\nPreorder traversal of binary tree is \n");
     printBoundaryNodesLeft(root);
     if(root->right)	
     printBoundaryNodesRight(root->right);
     getchar();
     return 0;
}
