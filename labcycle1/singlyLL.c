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

void insertAtPos(List *l,int data,int pos)
{
	Node *n=l->head,*prev=NULL;
	int i=0;
	if(pos<=0)
	{
		printf("Position does not exist\n");
		return;
	}
	if(pos==1)
	{
		Node *new_node=newNode(data);//put this here,coz if pos doesnot exist then this node will not be created
		new_node->next=l->head;
		l->head=new_node;
		if(l->tail==NULL)
			l->tail=l->head;
		return;
	}
	while(n!=NULL && i<pos-1)//i=1 then i<pos *****
	{
		prev=n;
		n=n->next;
		i++;
	}
	if(n==NULL)
	{
		printf("Position does not exist\n");
		return;
	}
	Node *new_node=newNode(data);
	prev->next=new_node;
	new_node->next=n;//tail will remain as it is, don't need to alter
}

void insertAfterKey(List *l, int key, int data)
{
	Node *n = l->head;
	while(n!=NULL && n->data!=key)
		n = n->next;
	if(n==NULL)
	{
		printf("Element %d doesn't exist in the list\n", key);
		return;
	}
	Node *new_node = newNode(data);
	new_node->next = n->next;
	n->next = new_node;
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

void DeleteValue(List *l,int data)
{
	Node *n=l->head,*prev=NULL;
	if(l->head->data==data)
	{
		DeleteHead(l);
		return;
	}
	while(n!=NULL && n->data!=data)
	{
		prev=n;
		n=n->next;
	}
	if(n==NULL)
	{
		printf("Element with value %d does not exist in the list\n",data);
		return;
	}
	Node *temp=n;
	prev->next=n->next;
	if(l->tail==temp)
		l->tail=prev;
	free(temp);
}

int findMin(List *l)
{
	Node *n=l->head;
	if(l->head==NULL)
	{
		printf("There are no elements in the list\n");
		return -1;
	}
	int min=n->data;
	n=n->next;
	while(n!=NULL)
	{
		if(n->data<min)
			min=n->data;
		n=n->next;
	}
	return min;
}

int findMax(List *l)
{
	Node *n=l->head;
	if(l->head==NULL)
	{
		printf("There are no elements in the list\n");
		return -1;
	}
	int max=n->data;
	n=n->next;
	while(n!=NULL)
	{
		if(n->data>max)
			max=n->data;
		n=n->next;
	}
	return max;
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
	List *l=newList();
	int option;
	do
	{
		printf("\nMenu :\n");
		printf("1. Insert At Tail\n");
		printf("2. Insert At Position\n");
		printf("3. Insert after a given element\n");
		printf("4. Delete At Head\n");
		printf("5. Delete perticular value\n");
		printf("6. Delete minimum element\n");
		printf("7. Delete maximum element\n");
		printf("8. Exit\n");
		printf("Enter option : ");
		scanf("%d",&option);
		if(option==1)
		{
			int data;
			printf("Enter the data : ");
			scanf("%d",&data);
			insertTail(l,data);
		}
		else if(option==2)
		{
			int data,pos;
			printf("Enter the data and position : ");
			scanf("%d%d",&data,&pos);
			insertAtPos(l,data,pos);
		}
		else if(option==3)
		{
			int data,key;
			printf("Enter the data and Element after which data is to be inserted : ");
			scanf("%d%d",&data,&key);
			insertAfterKey(l, key, data);
		}
		else if(option==4)
			DeleteHead(l);
		else if(option==5)
		{
			int data;
			printf("Enter the data to be deleted : ");
			scanf("%d",&data);
			DeleteValue(l,data);
		}
		else if(option==6)
		{
			int min=findMin(l);
			DeleteValue(l,min);
			printf("The minimum element deleted is %d\n",min);
		}
		else if(option==7)
		{
			int max=findMax(l);
			DeleteValue(l,max);
			printf("The maximum element deleted is %d\n",max);
		}
		PrintList(l);
	}while(option!=8);
	freeList(l);
	free(l);
	return 0;
}
