# include<stdio.h>
# include<stdlib.h>
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
	Q->array=malloc(Q->capacity*sizeof(int));
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

void enQueue(struct Queue *Q, int data){
	if(isQueueFull(Q))
		printf("Queue is FUll\n");
	else{
		Q->rear=(Q->rear+1)%Q->capacity;
		Q->array[Q->rear]=data;
		printf("Enqueue %d\n",Q->array[Q->rear]);
		if(Q->front==-1)
			Q->front=Q->rear;	
	}
}

int deQueue(struct Queue *Q){
	int data;
	if(isQueueEmpty){
		printf("Queue is Empty\n");
		return 0;	
	}
	data=Q->array[Q->front];
	if(Q->front == Q->rear)
		Q->front=Q->rear=-1;
	else
		Q->front=(Q->front+1)%Q->capacity;
	return data;
}

void deleteQueue(struct Queue *Q){
	if(Q)
		free(Q);
		
}

/*Enqueue 9
Enqueue 8
Enqueue 7
Enqueue 6
Enqueue 5
Enqueue 4
Enqueue 3
Enqueue 2
Enqueue 1
Enqueue 0
Enqueue -1
Enqueue -2
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0
Queue is Empty
Dequeue 0*/

void main(){
	struct Queue *Q=queueDef(20);	
	enQueue(Q,9);
	enQueue(Q,8);
	enQueue(Q,7);
	enQueue(Q,6);
	enQueue(Q,5);
	enQueue(Q,4);
	enQueue(Q,3);
	enQueue(Q,2);
	enQueue(Q,1);
	enQueue(Q,0);
	enQueue(Q,-1);
	enQueue(Q,-2);
	for(int i=0;i<15;i++)
		printf("Dequeue %d\n",deQueue(Q));
}
