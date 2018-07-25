// E1,E2,E3,D,D,E4,E5,D,D,D,E6,E7,D,E8,D
/*
E1 Q1->1 ;Q2->
E2 Q1->2-1 ;Q2->
E3 Q1->3-2-1 ;Q2
D Q1-> Q2->1-2-3; Q2->1-2
D Q1-> Q2->1
E4 Q1->4-1
E5 Q1->5-4-1
D Q1->
*/


# include<stdio.h>
# include<stdlib.h>
struct Stack{
	struct Queue *queue1;
	struct Queue *queue2;	
};


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

struct Stack *createStack(int size){
	struct Stack *S=malloc(sizeof(struct Stack));
	if(!S)
		return NULL;
	S->queue1=queueDef(size);
	S->queue2=queueDef(size);	
	return S;
}

void enQueue(struct Queue *Q, int data){
	/*if(isQueueFull(Q))
		printf("Queue is FUll\n");
	else{*/
		Q->rear=(Q->rear+1)%Q->capacity;
		Q->array[Q->rear]=data;
		printf("Enqueue %d\n",Q->array[Q->rear]);
		if(Q->front==-1)
			Q->front=Q->rear;	
	//}
}

int deQueue(struct Queue *Q){
	int data;
	/*if(isQueueEmpty(Q)){
		printf("Queue is Empty\n");
		return 0;	
	}*/
	data=Q->array[Q->front];
	if(Q->front == Q->rear)
		Q->front=Q->rear=-1;
	else
		Q->front=(Q->front+1)%Q->capacity;
	return data;
}

int isQueueEmpty(struct Queue *Q){
	return (Q->front == -1);
}

int isQueueFull(struct Queue *Q){
	return ((Q->rear+1)%Q->capacity == Q->front);
}


void Push(struct Stack *S,int data){
	int qData;
	while(!isQueueEmpty(S->queue2)){
		qData=deQueue(S->queue2);
		enQueue(S->queue1,qData);	
	}
	enQueue(S->queue1,data);
}

int Pop(struct Stack *S){
	int qData;
	while(!isQueueEmpty(S->queue1)){
		qData=deQueue(S->queue1);
		enQueue(S->queue2,qData);	
	}
	return deQueue(S->queue2);
}

void deleteStack(struct Stack *S){
	if(S)
		free(S);
}


int queueSize(struct Queue *Q){
	return (Q->rear-Q->front+1)%Q->capacity;
}

void deleteQueue(struct Queue *Q){
	if(Q)
		free(Q);
		
}
/*
nqueue 9
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
Enqueue 9
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
Pop 9
Pop 8
Pop 7
Pop 6
Pop 5
Pop 4
Pop 3
Pop 2
*/
void main(){
	struct Stack *S=createStack(20);	
	Push(S,9);
	Push(S,8);
	Push(S,7);
	Push(S,6);
	Push(S,5);
	Push(S,4);
	Push(S,3);
	Push(S,2);
	Push(S,1);
	Push(S,0);
	Push(S,-1);
	Push(S,-2);
	int a;
	for(int i=0;i<8;i++){
		a = Pop(S);
		if(a)
			printf("Pop %d\n",a);
	}
}





