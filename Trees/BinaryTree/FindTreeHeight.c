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
void findHeight(struct node* root, int* max,int count)
{
	if(root==NULL)
	return;
	else
	{
		count++;
		if(count>*max)
		*max=count;
		findHeight(root->left,max,count);
		findHeight(root->right,max,count);
	
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
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->right= newNode(6);
    root->left->right->right = newNode(7);
    root->left->right->right->left = newNode(12);
 
    printf("The maximum height of the Tree is \n");
    int max=0;
    int count=0;		
    findHeight(root,&max,count);
    printf("%d     ",max);
    return 0;
}
