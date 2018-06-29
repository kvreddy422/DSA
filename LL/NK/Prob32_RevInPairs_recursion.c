# include <stdio.h>
# include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};


// Reverse the Linked List; ex: 1->2->3->4->X turns out to be 2->1->4->3->X; 
/*This Program might not work.The reason is that it you have given head=head->next->next before calling the recusion function. That means, you can't access the first 2 elements no matter what. Even if you put some conditional statements to access it, the code runs in every reursion*/

struct node *ReversePairWise(struct node *head){
	struct node *a=NULL,*b=NULL,*out=NULL,*headStore=NULL;
	headStore=head;
	while (head){
			if(head->next)
				{
					a=head->next;
					if(a->next!=NULL){
						b=a->next;																	
					}
					a->next=head;
					head->next=b;
				}
			else
				return head;
			if(head->next){
			if(head->next->next)						
			out = ReversePairWise(head->next->next);
			}					
	}
	return head;
	
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
  if(head==NULL){
	printf("No head present");
	return;
  }
				
  while(head->next!=NULL)
  {
  printf("%d->",head->data);
  head=head->next;
  }
  printf("%d",head->data);
  printf("\n");
 // head=headStore;	
}

int main()
{
  struct node *head = NULL;
  insertBegin(&head,7);
  // inserts 5 at the begining ; LL = 5->7->NULL
  insertBegin(&head,5);
  insertBegin(&head,10);
  // inserts 12 at end; LL = 5->7->12->NULL
  //insertEnd(head,22); 
  //insertEnd(head,33);
  //insertEnd(head,12);
  //insertEnd(head,44);
  //insertEnd(head,55);	 
  //insertEnd(head,4); // 5->7->12->4->NULL 
  // insertMiddle(a,b,c,d) a= address of head; b= data; c=postion; d= flag flag (0=postion from head; 1= check for that data and insert after that node) 5->
  //insertMiddle(head,21,1,0); // 5->7->12->21->4->NULL
 // insertMiddle(head,22,10,0); // Not possible
  //insertMiddle(&head,23,1,0); // 5->23->7->12->21->4->NULL
  //insertMiddle(&head,24,21,1); // Placed after node with data 23
  
  printf("\n List before Revesing ");	
  printList(head);
  head=ReversePairWise(head);  	
  //ReversePairWise(head);
  printf("\n List after Revesing ");	
  printList(head);		
  return 0;  
}

