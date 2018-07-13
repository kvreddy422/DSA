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

int search(int array[],int check,int n){
	for(int i=0;i<n;i++){
		if(array[i]==check)
			return i;
		return -1;	
	}
}
 
void printPostorder(int in[], int pre[], int n){
	// The first element in pre[] is always root, search it
   // in in[] to find left and right subtrees
   int root = search(in, pre[0], n);
 
   // If left subtree is not empty, print left subtree
   if (root != 0)
      printPostorder(in, pre+1, root);
 
   // If right subtree is not empty, print right subtree
   if (root != n-1)
      printPostorder(in+root+1, pre+root+1, n-root-1);
   printf("%d ",pre[0]);
				
}	

int main()
{
    int in[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int pre[] =  {8,4,2,1,3,6,5,7,12,10,9,11,14,13,15}; 
    struct tree *root  = newNode(8);
     root->left = newNode(4);
     root->right = newNode(12);
     root->left->left = newNode(2);
     root->left->right = newNode(6);
     root->right->left = newNode(10);
     root->right->right = newNode(14); 
     root->left->left->left = newNode(1);
     root->left->left->right = newNode(3);
     root->left->right->left = newNode(5);
     root->left->right->right = newNode(7);
     root->right->left->left = newNode(9);
     root->right->left->right = newNode(11);
     root->right->right->left = newNode(13); 	
     root->right->right->left = newNode(15); 	
     printPostorder(in,pre,sizeof(in)/sizeof(in[0]));	
     getchar();
     return 0;
}
