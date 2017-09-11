# include <stdio.h>

struct node{
  int data;
  struct node *next;
};

void push(struct node** head_ref, int new_data){
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data=new_data;
  new_node->next=(*head_ref);
  (*head_ref) = new_node;
}
void insertAfter(struct node* prev_node, int new_data){
  struct node* new_node = (struct node*) malloc(sizeof(struct node));     

  if(prev_node==NULL){
    new_node->next=NULL;
    new_node->data=new_data;
    return;
  }
  struct node* temp_node= prev_node->next;  
  prev_node->next=new_node;
  new_node->data=new_data; 
  new_node->next=temp_node;
  return;
}

void printList (struct node *node){
  while(node!=NULL){
    printf(" %d ",node->data);
    node=node->next;
  }
}

int main(){
  struct node* head = NULL;
  push(&head,4);
  insertAfter(head,7);
  printf("\nThe list is\n");
  printList(head);
  insertAfter(head,9);
  insertAfter(head,1);
  printf("\nUpdated list is\n");
  printList(head);
  return 0;
}
