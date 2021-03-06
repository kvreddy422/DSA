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

void enQueue(struct Queue *Q, int N){
	if(isQueueFull(Q))
		printf("Queue is FUll\n");
	else{
		Q->rear=(Q->rear+1)%Q->capacity;
		Q->array[Q->rear]=N;
		if(Q->front==-1)
			Q->front=Q->rear;	
	}
}

int deQueue(struct Queue *Q){
	int N;
	if(isQueueEmpty(Q)){
		return 0;	
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
Complexity check
enQueue(Q,vertex);  takes -> O(1)
the outer while loop will have all the vertics - so O(V)
the inner loop can loop through V-1 times so O(V*(V-1))
but this is never the case - if innner loop is V-1 outer reduces to 1 - so its O(V-1)
worst case might be O(V*V) but it is very less than that around O(V+E)
*/
void BFS(struct Graph *G,int vertex){
	printf("Visited %d \n", vertex); // Print the given node
	struct Queue *Q = queueDef(10);
	enQueue(Q,vertex); 
	G->visited[vertex]=1; // mark the node as visited
	while(!isQueueEmpty(Q)){ // loop until the queue is empty
		int vertexNew = deQueue(Q); // get the enqueued node
		struct node *N = G->adjLists[vertexNew]; // get the ajacent of it ; basically the breath first
		while(N){ // now using adjacent list loop till u complete all the adajent nodes
			if(G->visited[N->vertex]==0){ // check for unvisited nodes in the graph
				enQueue(Q,N->vertex); // if found put it in the queue 
				printf("Visited %d \n",N->vertex); 
				G->visited[N->vertex]=1; // assign the node as a visited one
			}
			N=N->next; // loop throught the adjLists
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
	BFS(G,2);
}
