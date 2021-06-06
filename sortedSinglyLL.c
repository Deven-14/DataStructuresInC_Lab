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
};
typedef struct list List;

List* newList()
{
	List *l=(List*)malloc(sizeof(List));
	l->head=NULL;
	return l;
}

void insertInSortedOrder(List *l,int data)
{
	Node *new_node = newNode(data);
	Node *n = l->head, *prev=NULL;
	while(n!=NULL && n->data<data)
	{
		prev=n;
		n=n->next;
	}
	if(prev==NULL)//add at head
	{
		new_node->next = l->head;
		l->head = new_node;
	}
	else
	{
		new_node->next = n;
		prev->next = new_node;
	}
}

void DeleteHead(List *l)
{
	if(l->head==NULL)
		return;
	Node *temp=l->head;
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

int main()
{
	List *l = newList();
	int option;
	do
	{
		printf("\nMenu :\n");
		printf("1. Insert(Sorted Order)\n");
		printf("2. Delete head\n");
		printf("3. Exit\n");
		printf("Enter option : ");
		scanf("%d",&option);
		if(option==1)
		{
			int data;
			printf("Enter the data : ");
			scanf("%d",&data);
			insertInSortedOrder(l,data);
		}
		else if(option==2)
			DeleteHead(l);
		PrintList(l);
	}while(option!=3);
	freeList(l);
	free(l);
	return 0;
}
