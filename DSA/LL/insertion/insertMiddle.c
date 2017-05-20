# include <stdio.h>

struct node{
  int data;
  struct node *next;
};

void insertAfter(struct node* prev_node, int new_data){
  struct node* next_node = (struct node*) malloc(sizeof(struct node));     

  if(prev_node==NULL){
    next_node->next=NULL;
    next_node->data=new_data;
    return;
  }
  struct node* temp_node= prev_node->next;  
  prev_node->next=next_node;
  prev_node->data=new_data;
  next_node->next=temp_node;
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
  insertAfter(head,7);
  printf("The list is\n");
  printList(head);
  insertAfter(head,9);
  insertAfter(head,1);
  printf("Updated list is\n");
  printList(head);
  return 0;
}
