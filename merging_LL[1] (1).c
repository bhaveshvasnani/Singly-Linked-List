#include <stdio.h>
struct node
	{
		int data;
		struct node *next;
	};
struct node *head1,*head2,*n1, *last, *last1;
int n;
struct node* create_list(struct node *head,int n);
struct node* display(struct node *head);
struct node* merge(struct node *head1,struct node *head2);
void main()
{
	printf("\nNumber of nodes required for the first list\n");
	scanf("%d",&n);
	head1=NULL;
	head1=create_list(head1,n);
	last = display(head1);
	printf("\nNumber of nodes required for the second list\n");
	scanf("%d",&n);
	head2=NULL;
	head2=create_list(head2,n);
	last1=display(head2);
	printf("\nList after merging\n");
	last=merge(head1,head2);
	display(head1);
}
struct node* create_list(struct node *head,int n)
{
	struct node *temp;
	int i;
	n1=(struct node *)malloc(sizeof(struct node *));
	printf("Enter number\n");
	scanf("%d",&n1->data);
	n1->next=NULL;
	head = n1;
	for (i=0;i<n-1;i++)
	{
		temp=(struct node *)malloc(sizeof(struct node *));
		printf("Enter number\n");
		scanf("%d",&temp->data);
		temp->next=NULL;
		n1->next=temp;
		n1=temp;
	}
	printf("List created\n");
	return head;
}
struct node* display(struct node *head)
{
	struct node *a;
	a=head;
	while(a!=NULL)
    {
    printf("%d\t",a->data);
    a=a->next;
    }
    return a;
}
struct node* merge(struct node *head1,struct node *head2)
{
	struct node *w;
	w=head1;
	while(w->next!=NULL)
    {
    w=w->next;
    }
    w->next=head2;
	return w;
}
