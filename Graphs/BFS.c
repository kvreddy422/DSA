# include<stdio.h>
# include<stdlib.h>

// BFS is basically a level order traversal. All you need to do is it use the concept of Queues to store them - same as that of Level order of trees 
struct node{
	int vertex; // value of the node in the graph
	struct node *next; // to traverse to the next from a particular node
};

struct Graph{
	int noVertices; // May be the total no of nodes in the Graph
	int *visited; // to check if a node is already visited or not
	struct node **adjLists; 
};


////////////////////////////////////////////////////////
struct Queue{
	int front, rear;
	int capacity;
	struct node **array;
};

struct Queue *queueDef(int size){
	struct Queue *Q = malloc(sizeof(struct Queue));
	if(!Q)
		return NULL;
	Q->front=Q->rear=-1;
	Q->capacity=size;
	Q->array=malloc(Q->capacity*sizeof(struct node));
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

void enQueue(struct Queue *Q, struct node *N){
	if(isQueueFull(Q))
		printf("Queue is FUll\n");
	else{
		Q->rear=(Q->rear+1)%Q->capacity;
		Q->array[Q->rear]=N;
		if(Q->front==-1)
			Q->front=Q->rear;	
	}
}

struct node* deQueue(struct Queue *Q){
	struct node *N;
	if(isQueueEmpty(Q)){
		return NULL;	
	}
	N=Q->array[Q->front];
	if(Q->front == Q->rear)
		Q->front=Q->rear=-1;
	else
		Q->front=(Q->front+1)%Q->capacity;
	return N;
}


////////////////////////////////////////////////////////

struct Graph *createGraph(int graphSize){
	struct Graph *G = malloc(sizeof(struct Graph));
	G->noVertices = graphSize;
	G->visited = malloc(graphSize*sizeof(int));
	G->adjLists = malloc(graphSize*sizeof(struct node*));
	int i;
	for(i=0;i<graphSize;i++){
		G->visited[i]=0; // visited is initially set to 0
		G->adjLists[i]=NULL;	// the list is intitially NULL or empty 
	}
	return G;
}

struct node *createNode(int vertex){
	struct node *newNode = malloc(sizeof(struct node));
	newNode->next=NULL;
	newNode->vertex=vertex;
	return newNode;
}

void addEdge(struct Graph *G,int src,int dest){
	struct node *newNode = createNode(dest);
	newNode->next = G->adjLists[src];
	G->adjLists[src] = newNode;

	newNode = createNode(src);
	newNode->next = G->adjLists[dest];
	G->adjLists[dest] = newNode;
}

void printGraph(struct Graph *G){
	int i;
	for(i=0;i<G->noVertices;i++){
		struct node *temp = G->adjLists[i];
		printf("\n Adjacency list of vertex %d\n ", i);
		while(temp){
			printf("%d -> ", temp->vertex);
			temp=temp->next;		
		}
		printf("\n");
	
	}
} 
/*
 Adjacency list of vertex 0
 1 -> 

 Adjacency list of vertex 1
 4 -> 2 -> 0 -> 

 Adjacency list of vertex 2
 3 -> 1 -> 

 Adjacency list of vertex 3
 4 -> 2 -> 

 Adjacency list of vertex 4
 1 -> 3 -> 
Visited 0 
Visited 4 
Visited 2 
Visited 1 
Visited 3 
[Inferior 1 (process 8380) exited with code 01]


*/
void BFS(struct Graph *G,int vertex){
	struct Queue *Q = queueDef(10);
	struct node *present = G->adjLists[vertex];
	enQueue(Q,present);
	G->visited[vertex]=1;
	printf("Visited %d \n",vertex);
	while(!isQueueEmpty(Q)){
		struct node *N = deQueue(Q);
		N=G->adjLists[N->vertex];
		while(N){
			if(G->visited[N->vertex]==0){
				enQueue(Q,N);
				printf("Visited %d \n", N->vertex);
				G->visited[N->vertex]=1;
			}
			N=N->next; // Need to be outside? Why -> there might be some elements in the AdjLists of a particular node that are already visited; we just need to pass through without storing 					      them in queue
		}	
	}
}
void main(){
	struct Graph *G = createGraph(5);
	addEdge(G,0,1);
	addEdge(G,1,2);
	addEdge(G,2,3);
	addEdge(G,3,4);
	addEdge(G,4,1);
	
	printGraph(G);
	BFS(G,0);
}
