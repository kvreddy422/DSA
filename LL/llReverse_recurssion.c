# include <stdio.h>
# include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};



/*Here is the code to reverse a LL. Ex: 1->2->3->4->5->6->7 turns out to be 7->6->5->4->3->2->1*/

struct node *reverseLL (struct node *head)
{
	struct node *temp=NULL;	
	while(head->next!=NULL)
	{
		temp=head->next;
		head->next=NULL;
		struct node *rev=reverseLL (temp);
		temp->next=head;
		printf ("Rev data is %d \t",rev->data);
		return rev ;
	}
		printf ("Head data is %d \t",head->data);
		return head; // The beauty of this code is the way it store the head value from last to first. That is head when head->next == NULl and rev when head->nex!= NULL are always the same
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
  while(head->next!=NULL)
  {
  printf("%d->",head->data);
  head=head->next;
  }
  printf("%d",head->data);
  printf("\n");
}


int main()
{
  struct node *head = NULL;
  // inserts 7 at the begining ; LL = 7->NULL 
  insertBegin(&head,7);
  // inserts 5 at the begining ; LL = 5->7->NULL
  insertBegin(&head,5);
  insertBegin(&head,10);
  // inserts 12 at end; LL = 5->7->12->NULL
  insertEnd(head,12); 
  insertEnd(head,4); // 5->7->12->4->NULL 
  // insertMiddle(a,b,c,d) a= address of head; b= data; c=postion; d= flag flag (0=postion from head; 1= check for that data and insert after that node) 5->
  insertMiddle(head,21,1,0); // 5->7->12->21->4->NULL
 // insertMiddle(head,22,10,0); // Not possible
  //insertMiddle(&head,23,1,0); // 5->23->7->12->21->4->NULL
  //insertMiddle(&head,24,21,1); // Placed after node with data 23
  printList(head);		
  head=reverseLL(head);
  printf("LL after revesing is \n");		
  printList(head);

  return 0;  
}

