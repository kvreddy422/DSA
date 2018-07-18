// Recursive C program for level order traversal of Binary Tree
#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left, *right;
};
 
/* Function protoypes */
void findMax(struct node* root, int* max);
struct node* newNode(int data);
 
/* Function to print level order traversal a tree*/
void findMax(struct node* root, int* max)
{
	if(root==NULL)
	return;
	else
	{
		if(root->data>*max) // max is a pointer and *max is the value of the pointer
		*max=root->data;
		findMax(root->left,max);
		findMax(root->right,max);
	
	}
	   	
		
}
 
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
 
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}
 
/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(111);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
 
    printf("The maximum num in the Tree is \n");
    int max=-1;	
    findMax(root,&max);
    printf("%d",max);
    return 0;
}
