#include <stdio.h>
struct node
	{
		int data;
		struct node *next;
	};
struct node *head1,*head2,*n1,*n2;
int n;
struct node *create_list(struct node *head,int n);
void display(struct node *head);
struct node *square_list(struct node *head);
void main()
{
	printf("\nNumber of nodes required for the first list\n");
	scanf("%d",&n);
	head1=NULL;
	head1=create_list(head1,n);
	display(head1);
	printf("\nLinked list with square terms\n");
	head2=square_list(head1);
	display(head2);
}
struct node *create_list(struct node *head,int n)
{
	struct node *temp;
	int i;
	n1=(struct node *)malloc(sizeof(int));	
	printf("Enter number\n");
	scanf("%d",&n1->data);
	n1->next=NULL;
	head1=n1;
	for (i=0;i<n-1;i++)
	{
		temp=(struct node *)malloc(sizeof(int));
		printf("Enter number\n");
		scanf("%d",&temp->data);
		temp->next=NULL;
		n1->next=temp;
		n1=temp;
	}
	printf("List created\n");
	return head1;
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
struct node *square_list(struct node *head)
{
	struct node *w,*n2,*temp;
	w=head;
	n2=(struct node *)malloc(sizeof(int));
	n2->data=(w->data)*(w->data);
	n2->next=NULL;
	head2=n2;
	while (w->next!=NULL)
	{
		w=w->next;
		temp=(struct node *)malloc(sizeof(int));
		temp->data=(w->data)*(w->data);
		temp->next=NULL;
		n2->next=temp;
		n2=temp;
	}
	return head2;
}
