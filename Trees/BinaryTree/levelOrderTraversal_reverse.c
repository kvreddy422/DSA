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

// Stack for the Level Order Tree
struct Stack{
	int top;
	int capacity;
	struct tree **array;	
};

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

struct Stack *createStack(int size){
	struct Stack *S=malloc(sizeof(struct Stack));
	if(!S)
		return NULL;
	S->capacity=size;
	S->top=-1;
	S->array= (struct tree **)malloc(Q->capacity*sizeof(struct tree));
	if(!S->array)
		return NULL;
	return S;
}

int stackIsFull(struct Stack *S){
	return (S->top+1==S->capacity);
}

int stackIsEmpty(struct Stack *S){
	return (S->top==-1);
}


void Push(struct Stack *S, struct tree *T){
	if(stackIsFull(S)){
		printf("Stack is Full\n");
		return;
	}
	S->top++;
	S->array[S->top]=T;
}

struct tree *Pop(struct Stack *S){
	if(stackIsEmpty(S)){
		return 0;	
	}
	return S->array[S->top--];
}

//QUEUE

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
// Level Order Traversal is done using Stacks

void printLevelorder(struct tree *node){
	struct Queue *Q=queueDef(20);
	struct tree *node_temp=node;
	if(!node)
		return;
	enQueue(Q,node);	
	while(node){
		node=deQueue(Q);
		Push(S,node);
		if(node==NULL)
			break;
		if(node->left)
			enQueue(Q,node->left);
		if(node->right)
			enQueue(Q,node->right);		
	}
	while(!stackIsEmpty(S)){
		printf("%d ",S->data);
	}

}

int main()
{
     struct tree *root  = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5); 	
     struct Stack *S=createStack(20);	
     printf("\nLevelorder traversal of binary tree is \n");
     printLevelorder(root);
     getchar();
     return 0;
}

