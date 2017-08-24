#include <stdio.h>
struct node
	{
		int data;
		struct node *next;
	};
struct node *n1,*head;
int n;
struct node *create_list(struct node *head,int n);
struct node *insert_beginning(struct node *head);
struct node *insert_end(struct node *head);
struct node *insert_position(struct node *head);
struct node *delete_beginning(struct node *head);
struct node *delete_end(struct node *head);
struct node *delete_position(struct node *head);
void count_nodes(struct node *head);
void display(struct node *head);
int main()
{
	printf("Number of nodes required initially\n");
	scanf("%d",&n);
	head=NULL;
	head=create_list(head,n);
	display(head);
	/*head=insert_beginning(head);
	display(head);
	head=insert_end(head);
	display(head);
	head=insert_position(head);
	display(head);
	head=delete_beginning(head);
	display(head);
	head=delete_end(head);
	display(head);*/
	head=delete_position(head);
	display(head);
	count_nodes(head);
}
struct node *create_list(struct node *head,int n)
{
	struct node *temp;
	int i;
	n1=(struct node *)malloc(sizeof(struct node *));
	printf("Enter number\n");
	scanf("%d",&n1->data);
	n1->next=NULL;
	head=n1;
	for (i=0;i<n-1;i++)
	{
		temp=(struct node *)malloc(sizeof(struct node *));
		printf("\nEnter number\n");
		scanf("%d",&temp->data);
		temp->next=NULL;
		n1->next=temp;
		n1=temp;
	}
	printf("List created\n");
	return head;
}
struct node *insert_beginning(struct node *head)
{
	struct node *ib;
	ib=(struct node *)malloc(sizeof(struct node *));
	printf("\nEnter number\n");
	scanf("%d",&ib->data);
	ib->next=head;
	head=ib;
	printf("Inserted in the beginning\n");
	return head;
}
struct node *insert_end(struct node *head)
{
	struct node *ie;
	ie=(struct node *)malloc(sizeof(struct node *));
	printf("\nEnter number\n");
	scanf("%d",&ie->data);
	n1=head;
	while(n1->next!=NULL)
	{
	    n1=n1->next;
	}
	n1->next=ie;
	ie->next=NULL;
	printf("Inserted at the end\n");
	return head;
}
struct node *insert_position(struct node *head)
{
	struct node *ip,*prev;
	int i=1,q;
	printf("\nEnter position where you want to insert\n");
	scanf("%d",&q);
	ip=(struct node *)malloc(sizeof(struct node *));
	printf("Enter number\n");
	scanf("%d",&ip->data);
	prev=head;
	while(i<q-1)
	{
		prev=prev->next;
	}
	ip->next=prev->next;
	prev->next=ip;
	printf("\nInserted at the position\n");
	return head;
}
struct node *delete_beginning(struct node *head)
{
	struct node *temp;
	temp=head->next;
	free(head);
	head=temp;
	printf("\nDeleted from the beginning\n");
	return head;
}
struct node *delete_end(struct node *head)
{
	struct node *t,*temp;
	temp=head;
	while(temp->next != NULL)
  	{
    	t=temp;
    	temp=temp->next;
  	}
  	t->next=NULL;
	free(temp);
	printf("\nDeleted from the end\n");
	return head;
}
struct node *delete_position(struct node *head)
{
	struct node *ip,*prev;
	int i=1,q;
	printf("\nEnter position from which you want to delete\n");
	scanf("%d",&q);	
	prev=head;
	while(i<q-1)
	{
		prev=prev->next;
	}
	ip=prev->next;
	prev->next=ip->next;
	free(ip);
	printf("Deleted from the position\n");
	return head;
}
void count_nodes(struct node *head)
{
	int k=0;
	struct node *j;
	j=head;
	while(j!=NULL)
	{
		k++;
		j=j->next;
	}
	printf("\nCount = %d\n",k);
}
void display(struct node *head)
{
	struct node *a;
	a=head;
	while(a!=NULL)
    {
    printf("%d\t",a->data);
    a=a->next;
    }
}
