#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;

Node* newNode(int data)
{
	Node *n=(Node*)malloc(sizeof(Node));
	n->data=data;
	n->next=NULL;
	return n;
}

struct list
{
	Node *head;
	Node *tail;
	int min;
	int max;
};
typedef struct list List;

List* newList()
{
	List *l=(List*)malloc(sizeof(List));
	l->head=NULL;
	l->tail=NULL;
	return l;
}

void insertTail(List *l,int data)
{
	Node *new_node=newNode(data);
	if(l->head==NULL)
		l->head=l->tail=new_node;
	else
	{
		l->tail->next=new_node;
		l->tail=new_node;
	}
}

void DeleteHead(List *l)
{
	Node *temp=l->head;
	if(l->head==NULL)
		return;
	else if(l->head==l->tail)
		l->head=l->tail=NULL;
	else
		l->head=l->head->next;
	free(temp);
}

void PrintList(List *l)
{
	printf("The List is : ");
	Node *n=l->head;
	if(n==NULL)
		printf("The list is empty");
	while(n!=NULL)
	{
		printf("%d ",n->data);
		n=n->next;
	}
	printf("\n");
}

void freeList(List *l)
{
	Node *n=l->head,*temp;
	while(n!=NULL)
	{
		temp=n;
		n=n->next;
		free(temp);
	}
}

List* inputList()
{
	int n;
	List *l=newList();
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	int data;
	printf("Enter the elements in sorted order : ");
	for(int i=0;i<n;++i)
	{
		scanf("%d",&data);
		insertTail(l,data);
	}
	return l;
}

List* concatinate(List *l1,List *l2)
{
	List *l3=newList();
	Node *n1=l1->head;
	Node *n2=l2->head;
	while(n1!=NULL && n2!=NULL)
	{
		while(n1!=NULL && n2!=NULL && n1->data<=n2->data)
		{
			insertTail(l3,n1->data);
			n1=n1->next;
			DeleteHead(l1);
		}
		while(n1!=NULL && n2!=NULL && n2->data<=n1->data)
		{
			insertTail(l3,n2->data);
			n2=n2->next;
			DeleteHead(l2);
		}
	}
	if(n1!=NULL)
	{
		while(n1!=NULL)
		{
			insertTail(l3,n1->data);
			n1=n1->next;
		}
	}
	if(n2!=NULL)
	{
		while(n2!=NULL)
		{
			insertTail(l3,n2->data);
			n2=n2->next;
		}
	}
	return l3;
}

int main()
{
	printf("List 1\n");
	List *l1=inputList();
	printf("List 2\n");
	List *l2=inputList();
	List *l3=concatinate(l1,l2);
	PrintList(l3);
	freeList(l3);
	free(l3);
	freeList(l2);
	free(l2);
	freeList(l1);
	free(l1);
	return 0;
}
