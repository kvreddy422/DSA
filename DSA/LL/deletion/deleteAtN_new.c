// This program is to delete the nodes at a given position

# include<stdio.h>
# include<stdlib.h>

// Creation of a node ; Made of a pointer and an integer; Integer is used to store data and pointer is used to connect the LL or for positioning
struct node
{
	int data;
	struct node *next;
};

// Pushing data into the LL --- it's not the main fuction

void Add_Node(struct node **head, int data_new)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->next=(*head);
	new_node->data=data_new;
	(*head)=new_node;
}

// Delete a node at a given position in a Linked List

void Delete_Node(struct node **head, int position)
{
	if(*head==NULL)
	return;
	struct node *temp_node = *head;
	if(position==0)
	{
		*head=temp_node->next;
		free(temp_node);
		return;
	}
	int i=0;	
//	for(i=0; i<position || *head->next==NULL ; i++ )
//	{
		
//	}
	
	
	
}
void Print_List(struct node *head)
{
	printf("The list is : \n");
		while(head!=NULL)
		{
		printf("%d->",head->data);
		head=head->next;
		}
}
int main()
{
	struct node *head = NULL;
	
	Add_Node(&head,10);
	Add_Node(&head,20);
	Add_Node(&head,30);
	Add_Node(&head,40);
	Add_Node(&head,50);
	
	Print_List(head);
}



