# include<stdio.h>
# include<stdlib.h>
// Declared a Struct called Linked List
struct LL{
	int data;
	struct LL *next;
};

// Using this *head is not working out. But I haven't yet understood why it is not. It doesn't work in the sense, it is like call by value
void insertAtBegin(struct LL *head, int data){
	struct LL *new_node= (struct LL *)malloc(sizeof(struct LL));
	//struct LL *headStore=head;
	if(!new_node){
		printf("Memory Error");
	}
	new_node->data=data;
	new_node->next=head;
	head=new_node;
}

void insertAtBegin_DP(struct LL **head, int data){
	struct LL *new_node= (struct LL *)malloc(sizeof(struct LL));
	//struct LL *headStore=head;
	if(!new_node){
		printf("Memory Error");
	}
	new_node->data=data;
	new_node->next=(*head);
	(*head)=new_node;
}

struct LL *insertAtBegin_DP_Return(struct LL *head, int data){
	struct LL *new_node= (struct LL *)malloc(sizeof(struct LL));
	struct LL *headStore=head;
	if(!new_node){
		printf("Memory Error");
		return NULL;
	}
	new_node->data=data;
	new_node->next=(head);
	(head)=new_node;
	return headStore;
}

void printList(struct LL *head){
	if(head!=NULL){
		printf("%d->",head->data);
		head=head->next;
	}
	else
		printf("The LL is NULL\n");
}

// Now we are going to create the given Linked List

main(){
	printf("Creating a Linked List: \n");
	struct LL *head = NULL;
	insertAtBegin(head,10); // address of head is being sent to the LL
	printList(head);
	printf("\n");
	insertAtBegin_DP(&head,10); // address of head is being sent to the LL
	printList(head);
	printf("\n");
	head =insertAtBegin_DP_Return(head,10); // address of head is being sent to the LL
	printList(head);
	printf("\n");
	
}

