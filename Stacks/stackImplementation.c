# include<stdio.h>
# include<stdlib.h>
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

int stackIsFull(struct Stack *S){
	return ((S->top+1)%(S->capacity)==0);// This can't be used because if S->top = -1; S->top+1 =0; 0%x=0; So cahnge it to S->top+1==S->capacity
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

void deleteStack(struct Stack *S){
	if(S)
		free(S);
}

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
	for(int i=0;i<15;i++){
		a = Pop(S);
		if(a)
			printf("Pop %d\n",a);
	}
}

