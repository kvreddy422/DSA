# include<stdio.h>
// Linked List node decleration 
struct node{
	int data;
	struct node *next;		
};

struct node * insertAtBeginning(struct node *head, int data){
	printf("I am atleast here");
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=head->next;
	head->next=newNode; 
	return head;
	
}

// Copied
struct node * append(struct Node* head_ref, int new_data)
{
    /* 1. allocate node */
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
 
    struct node *last = head_ref;  /* used in step 5*/
 
    /* 2. put in the data  */
    new_node->data  = new_data;
 
    /* 3. This new node is going to be the last node, so make next of
          it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty, then make the new node as head */
    if (head_ref == NULL)
    {
       head_ref = new_node;
       return head_ref;
    }
 
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* 6. Change the next of last node */
    last->next = new_node;
    return head_ref;
}

void printList(struct node *head)
{
	while(head!=NULL){
	printf(" %d ", head->data);
	if(head)
	head = head->next;
	else 
	return 0;
}
}

int main()
{
	struct node *head = NULL;
	head=insertAtBeginning(head,7);	
	//head=append(head,6);
	//head=append(head,5);
	//head=append(head,4);
	
	printList(head);
	return 0;	
}
