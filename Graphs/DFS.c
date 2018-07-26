# include<stdio.h>
# include<stdlib.h>

struct node{
	int vertex; // value of the node in the graph
	struct node *next; // to traverse to the next from a particular node
};

struct Graph{
	int noVertices; // May be the total no of nodes in the Graph
	int *visited; // to check if a node is already visited or not
	struct node **adjLists; 
};

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

void DFS(struct Graph *G,int vertex){
	struct node *present = G->adjLists[vertex];
	G->visited[vertex]=1;
	printf("Visited %d \n", vertex);
	while(present){
		if(G->visited[present->vertex]==0)
			DFS(G, present->vertex);
		present=present->next;	
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
	DFS(G,2);
}
