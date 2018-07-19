# include<stdio.h>
#include <stdlib.h>
// The actual code implementation for the level order tree
// Data , Left and Right
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

// Queue for the Level Order Tree
struct Queue{
	int front, rear;
	int capacity;
	struct tree **array;
};

struct Queue *queueDef(int size){
	struct Queue *Q = malloc(sizeof(struct Queue));
	if(!Q)
		return NULL;
	Q->front=Q->rear=-1;
	Q->capacity=size;
	Q->array= (struct tree **)malloc(Q->capacity*sizeof(struct tree));
	if(!Q->array)
		return NULL;
	return Q;
}

int isQueueEmpty(struct Queue *Q){
	return (Q->front == -1);
}

int isQueueFull(struct Queue *Q){
	return ((Q->rear+1)%Q->capacity == Q->front);
}

int queueSize(struct Queue *Q){
	return (Q->rear-Q->front+1)%Q->capacity;
}

void enQueue(struct Queue *Q, struct tree *T){
	if(isQueueFull(Q))
		printf("Queue is FUll\n");
	else{
		Q->rear=(Q->rear+1)%Q->capacity;
		Q->array[Q->rear]=T;
		if(Q->front==-1)
			Q->front=Q->rear;	
	}
}

struct tree *deQueue(struct Queue *Q){
	int data;
	if(isQueueEmpty(Q)){
		printf("Queue is Empty\n");
		return 0;	
	}
	struct tree *T =Q->array[Q->front];
	if(Q->front == Q->rear)
		Q->front=Q->rear=-1;
	else
		Q->front=(Q->front+1)%Q->capacity;
	return T;
}



// Add a new node
struct tree* newNode(int data){
	struct tree *node = (struct tree*)malloc(sizeof(struct tree));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
// Level Order Traversal is done using Queues

/*Levelorder traversal of binary tree is 
1 .......
The program is not terminating 

*/
void printLevelorder(struct tree *node){
	struct Queue *Q=queueDef(20);
	if (node==NULL)
		return;
	else
		printf("%d ",node->data);		
	while(node){
		enQueue(Q,node);
		if(!isQueueEmpty){
			node = deQueue(Q);
			printf("%d ",node->data);		
		}
		else{
			node=NULL;
			return;		
		}
		if(node->left) // The error happens here as we are making node = NULL so that the loop terminates finally. Didn't loop into if this line executes 
			enQueue(Q,node->left);
		if(node->right)
			enQueue(Q,node->right);		
	}
}

int main()
{
     struct tree *root  = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5); 	
 
     printf("\nLevelorder traversal of binary tree is \n");
     printLevelorder(root);
     getchar();
     return 0;
}

