struct node
{
  int data;
  struct node *next;
};

void push(struct node **head_ref,int new_data)
{
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data=new_data;
  new_node->next=(*head_ref);
  (*head_ref)=new_node;
}
void printList(struct node *node)
{
  while(node)
    {
       printf("%d",node->data);
       node=node->next;
    }
}
int main(){
  struct node* head;
  push(&head,6);
  printf("\nThe linked List is:\n");
  printList(head);
  return 0;
}
