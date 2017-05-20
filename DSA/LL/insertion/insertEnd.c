# include<stdio.h>
struct node{
  int data;
  struct node *next;
};


void append(struct node** head_ref, int new_data){

  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  struct node *last = *head_ref;
  new_node->data= new_data;
  new_node->next=NULL;
  
  if(*head_ref==NULL)
  {
    *head_ref = new_node;
    return;
  }

  while(last->next!=NULL)
    last=last->next;
   
  last->next=new_node;
  return;
}

void printList(struct node *node){
  while(node != NULL)
  {
    printf(" %d",node->data);
    node=node->next;
  }
}

int main(){
  struct node* head = NULL;
  append(&head,6);
  printf("\nThe linked list is :");
  printList(head);
  append(&head,10);
  append(&head,1);
  append(&head,5);
  printf("\nThe linked list is :");
  printList(head);
  return 0;
}  
