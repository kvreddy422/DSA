# include<stdio.h>
# include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct Graph{
	int vertices;
	int *visited;
	struct node **adjLists;
};

struct Graph *createGraph(int noVertices){
	struct Graph *G = malloc(sizeof(struct Graph));
	G->vertices=noVertices;
	G->visited=malloc(noVertices*sizeof(int));
	G->adjLists=malloc(noVertices*sizeof(struct node));
	int i;
	for(i=0;i<noVertices;i++){
		G->visited[i]=0;
		G->adjLists[i]=NULL;	
	}
	return G;
}

struct node *createNode(int data){
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

void addEdge(struct Graph *G, int src, int dest){
	struct node *newNode = createNode(dest);
	newNode->next=G->adjLists[src];
	G->adjLists[src]=newNode;

	newNode = createNode(src);
	newNode->next=G->adjLists[dest];
	G->adjLists[dest]=newNode;
}

void printGraph(struct Graph *G){
	int v;
	for(v=1; v<G->vertices; v++){
		struct node *temp = G->adjLists[v];
		printf("\n Adjacency list of vertex %d\n ", v);
		while(temp){
			printf("%d -> ", temp->data);
			temp=temp->next;		
		}
		printf("\n");	
	}
}

int main(){
	struct Graph *G = createGraph(5);
	addEdge(G,1,2);
	addEdge(G,2,3);
	addEdge(G,3,4);
	addEdge(G,4,1);
	addEdge(G,1,3);
	
	printGraph(G);
}
