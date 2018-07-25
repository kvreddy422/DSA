//  e9,e8,e7,e3,d,d,e4,e5,d,d,e1
/*
e9 S1->9;S2->   
e8 S1->9-8;S2->
e7 S1->9-8-7;S2->
e3 S1->9-8-7-3;S2->
d S1->; S2->3-7-8-9; S2->3-7-8     9
d S1->; S2->3-7    8
e4 S1->7-3 S1->7-3-4; S2->
e5 S1->7-3-4-5; S2->
d S1->; S2->5-4-3-7; S2->5-4-3   7
d S1->; S2->5-4   3	
e1 S1->4-5; S1->4-5-1; S2->  	
*/

# include<stdio.h>
# include<stdlib.h>

struct Queue{
	struct Stack *stack1;   // I think this contains the stack;
	struct Stack *stack2;
};

struct Stack{
	int top;
	int capacity;
	int *array;	
};

struct Stack *createStack(int size){
	struct Stack *S=malloc(sizeof(struct Stack));
	if(!S)
		return NULL;
	S->capacity=size;
	S->top=-1;
	S->array=malloc(S->capacity*sizeof(int));
	if(!S->array)
		return NULL;
	return S;
}

struct Queue *queueDef(int size){
	struct Queue *Q = malloc(sizeof(struct Queue));
	if(!Q)
		return NULL;
	Q->stack1=createStack(size);
	Q->stack2=createStack(size);
}

int stackIsFull(struct Stack *S){
	return (S->top+1==S->capacity);
}

int stackIsEmpty(struct Stack *S){
	return (S->top==-1);
}

void Push(struct Stack *S,int data){
	if(stackIsFull(S)){
		printf("Stack is Full\n");
		return;
	}
	S->top++;
	S->array[S->top]=data;
}

int Pop(struct Stack *S){
	if(stackIsEmpty(S)){
		printf("Stack is Empty\n");
		return 0;	
	}
	return S->array[S->top--];
}


void enQueue(struct Queue *Q, int data){
	if(stackIsFull(Q->stack1))
		printf("Queue is FUll\n");
	else{
		int sData;
		while(!stackIsEmpty(Q->stack2)){
			sData=Pop(Q->stack2);
			Push(Q->stack1,sData);
		}
		Push(Q->stack1,data);
			
	}
}

int deQueue(struct Queue *Q){
///////////////////////////////////////////////////////
	int sData;
	if(stackIsEmpty(Q->stack1)){
		printf("Queue is Empty");
		return 0;
	}
	while(!stackIsEmpty(Q->stack1)){
		sData=Pop(Q->stack1);
		Push(Q->stack2,sData);
	}
	return Pop(Q->stack2);		
///////////////////////////////////////////////////////
}

void deleteQueue(struct Queue *Q){
	if(Q)
		free(Q);
		
}

void deleteStack(struct Stack *S){
	if(S)
		free(S);
}

/*
Dequeue 9
Queue is EmptyDequeue 0
Queue is EmptyDequeue 0
Queue is EmptyDequeue 0
Queue is EmptyDequeue 0
Queue is EmptyDequeue 0
Queue is EmptyDequeue 0
Queue is EmptyDequeue 0
Queue is EmptyDequeue 0
Queue is EmptyDequeue 0
Queue is EmptyDequeue 0
Queue is EmptyDequeue 0
Queue is EmptyDequeue 0
Queue is EmptyDequeue 0
Queue is EmptyDequeue 0
*/
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
	int a;
	for(int i=0;i<15;i++){
		a = deQueue(Q);
		printf("Dequeue %d\n",a);
	}
}

