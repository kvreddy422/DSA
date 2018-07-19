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
	int *array;
};

struct Queue *queueDef(int size){
	struct Queue *Q = malloc(sizeof(struct Queue));
	if(!Q)
		return NULL;
	Q->front=Q->rear=-1;
	Q->capacity=size;
	Q->array=malloc(Q->capacity*sizeof(tree));
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

void enQueue(struct Queue *Q, struct tree){
	if(isQueueFull(Q))
		printf("Queue is FUll\n");
	else{
		Q->rear=(Q->rear+1)%Q->capacity;
		Q->array[Q->rear]=tree;
		printf("Enqueue %d\n",Q->array[Q->rear]);
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
	strcut tree *T =Q->array[Q->front];
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
void printLevelorder(struct tree *node){
	if (node==NULL)
		return node;
	else
		printf("%d ",node->data);		
	while(node){
		struct Queue *Q=queueDef(20);
		enQueue(Q,node);
		if(!isQueueEmpty){
			node = deQueue(Q);
			printf("%d ",node->data);		
		}
		if(node->left)
			enQueue(node->left);
		if(node->right)
			enQueue(node->right);		
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
}/*
