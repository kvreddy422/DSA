# include <stdio.h>
# include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

int main()
{
  struct node *head = NULL,*headNew;
  // inserts 7 at the begining ; LL = 7->NULL 
  insertBegin(&head,2);
  // inserts 5 at the begining ; LL = 5->7->NULL
  insertBegin(&head,3);
  //insertBegin(&head,1);
  // inserts 12 at end; LL = 5->7->12->NULL
  insertEnd(head,4); 
  //insertEnd(head,5); // 5->7->12->4->NULL 
  // insertMiddle(a,b,c,d) a= address of head; b= data; c=postion; d= flag flag (0=postion from head; 1= check for that data and insert after that node) 5->
  //insertMiddle(head,21,1,0); // 5->7->12->21->4->NULL
 // insertMiddle(head,22,10,0); // Not possible
  //insertMiddle(&head,23,1,0); // 5->23->7->12->21->4->NULL
  //insertMiddle(&head,24,21,1); // Placed after node with data 23
  
  printList(head);
  headNew=insertionSort(head);
  printf("\nHeadNew:%d\n",headNew->data);	
  printList(headNew);
  return 0;  
}
/*This code never works. The reason is that the 1st node... the intial node if replaced ex: 3->2->4 will not give 2->3->4; it is giving 3->4 as the output. The reason being you are using temp variable intially is 3. Now it can't change to 2. It will remain 3
*/
struct node *insertionSort(struct node *head)
{
  struct node *temp,*head1,*head3,*tempPrev,*headPrev,*temp2;
  temp=head;
  head1=head;
  tempPrev=NULL;
  headPrev=NULL;
  temp2=NULL;
  while(head1)	
  {
    temp2=head;
    tempPrev=NULL;
    head3=head1;			
    while(temp2!=head1)
    {
	if(temp2->data>head1->data){
		headPrev->next=head1->next;
		head1->next=temp2;
		if(tempPrev!=NULL)
		tempPrev->next=head1;
		else
		temp=head1;
		break;	
	}
	tempPrev=temp2;
	if(temp2->next)
        	temp2=temp2->next;
	else
		break; 	
		
    }
  head1=head3;
  headPrev=head1;
  if(head1->next)		
  	head1=head1->next;
  else
  	break;		
  }
  return temp;	  	  
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


