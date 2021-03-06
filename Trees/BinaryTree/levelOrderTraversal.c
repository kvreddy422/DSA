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
		return NULL;	
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
eue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll
Queue is FUll
1 Queue is FUll 

*/
void printLevelorder(struct tree *node){
	struct Queue *Q=queueDef(20);
	struct tree *node_temp=node;
	if(!node)
		return;
	enQueue(Q,node);	
	while(node){
		node=deQueue(Q);
		if(node==NULL)
			return;
		printf("%d ",node->data);
		if(node->left)
			enQueue(Q,node->left);
		if(node->right)
			enQueue(Q,node->right);		
	}	
	/*while(node_temp){
		printf("%d ",node->data);
		if(node_temp!=node)
			node_temp=deQueue(Q);
		if(node_temp==NULL && node_temp!=node)
			break;
		if(node_temp->left)
			enQueue(Q,node_temp->left);
		if(node_temp->right)
			enQueue(Q,node_temp->right);	
	}*/



	/*if (node==NULL)
		return;
	else
		printf("%d ",node->data);		
	while(node){
		enQueue(Q,node);
		if(!isQueueEmpty(Q)){
			node = deQueue(Q);
			printf("%d ",node->data);		
		}
		else{
			node=NULL;
			return;		
		}
		if(node->left)
			enQueue(Q,node->left);
		if(node->right)
			enQueue(Q,node->right);		
	}*/
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

