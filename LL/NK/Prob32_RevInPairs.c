# include <stdio.h>
# include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

int main()
{
  struct node *head = NULL;
  // inserts 7 at the begining ; LL = 7->NULL 
  insertBegin(&head,7);
  // inserts 5 at the begining ; LL = 5->7->NULL
  insertBegin(&head,5);
 // insertBegin(&head,10);
  // inserts 12 at end; LL = 5->7->12->NULL
  //insertBegin(&head,12); 
  //insertBegin(&head,4); // 5->7->12->4->NULL 
  // insertMiddle(a,b,c,d) a= address of head; b= data; c=postion; d= flag flag (0=postion from head; 1= check for that data and insert after that node) 5->
  //insertBegin(&head,21); // 5->7->12->21->4->NULL
 // insertMiddle(head,22,10,0); // Not possible
  //insertMiddle(&head,23,1,0); // 5->23->7->12->21->4->NULL
  //insertMiddle(&head,24,21,1); // Placed after node with data 23
  
  printList(head);
  //ReversePairWise(head);
  printf("\n List after Revesing");	
  printList(head);		
  return 0;  
}

// Reverse the Linked List; ex: 1->2->3->4->X turns out to be 2->1->4->3->X;

void ReversePairWise(struct node *head){
	printf("1\n");
	struct node *before, *present, *after, *headStore;
	headStore=head;
	while(head!=NULL){		
		if(head!=NULL)
		{
			before=head;
			printf("I am here");
		}
		if(head->next!=NULL)
			present=head->next;
		if(present->next!=NULL)
			after=present->next;
	present->next=before;
	before->next=after;
	head=after;
	}
	head=headStore;
}

void insertBegin(struct node **head, int data)
{
  struct node* new_node= (struct node*)malloc(sizeof(struct node));
  
  new_node->data=data;
  new_node->next=(*head);
  (*head)=new_node;

}
void insertEnd(struct node *head, int data)
{
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  
  new_node->data=data;
  
  while(head->next!=NULL)
    head=head->next;
  head->next=new_node;
  new_node->next=NULL;
}

void insertMiddle(struct node *head,int data,int pos_data,int flag)
{
  struct node* new_node=(struct node*) malloc(sizeof(struct node));
  new_node->data=data;
  if(flag==0)
    {
        int i=0;
	while(head->next!=NULL && i<=pos_data)
		{
			head=head->next;
			i++;
		}
        if(pos_data>i+1)
		printf("Cannot insert %d at the middle\n",data);
        else
	{  
		new_node->next=head->next;
       		head->next=new_node;
	}    		
    }
  else
    {
	while(head->next!=NULL)
	{
		if(head->data==data)
		{
			break;
		}
		else
		head=head->next;
	}
	if(head->data==data)
	{
		new_node->next=head->next;
		head->next=new_node;
	}
	else
		printf("Node with the given data not found \n");				
    }		
}
void printList(struct node *head)
{
  struct node *headStore=head;	
  while(head->next!=NULL)
  {
  printf("%d->",head->data);
  head=head->next;
  }
  printf("%d",head->data);
  printf("\n");
 // head=headStore;	
}