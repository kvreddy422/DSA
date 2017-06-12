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
  insertBegin(&head,10);
  insertBegin(&head,50);
  // inserts 12 at end; LL = 5->7->12->NULL
  insertEnd(&head,12); 
  insertEnd(&head,4); // 5->7->12->4->NULL 
  // insertMiddle(a,b,c,d) a= address of head; b= data; c=postion; d= flag flag (0=postion from head; 1= check for that data and insert after that node) 5->
  //insertMiddle(&head,21,3,0); // 5->7->12->21->4->NULL
  //insertMiddle(&head,22,10,0); // Not possible
  //insertMiddle(&head,23,1,0); // 5->23->7->12->21->4->NULL
  //insertMiddle(&head,24,23,1); // Placed after node with data 23
  
  printList(head);
  return 0;  
}

void insertBegin(struct node **head, int data)
{
  struct node* new_node= (struct node*)malloc(sizeof(struct node));
  
  new_node->data=data;
  new_node->next=(*head);
  (*head)=new_node;

}
void insertEnd(struct node **head, int data)
{
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  
  new_node->data=data;
  
  while(node->next!=NULL)
    node=node->next;
  node->next=new_node;
  new_node->next=NULL;
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
