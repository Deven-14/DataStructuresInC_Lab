#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node Node;

Node* newNode(int data)
{
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->prev = n;
	n->next = n;
	return n;
}

struct doublyLL
{
	Node *head;
	Node *tail;
};
typedef struct doublyLL DoublyLL;

DoublyLL* newDLL()
{
	DoublyLL *d = (DoublyLL*)malloc(sizeof(DoublyLL));
	d->head = NULL;
	d->tail = NULL;
	return d;
}

void InsertAtHead(DoublyLL *d, int data)
{
	Node *new_node = newNode(data);
	if(d->head == NULL)
	{
		d->head = new_node;
		d->tail = new_node;
		return ;
	}
	d->head->prev = new_node;
	d->tail->next = new_node;
	new_node->next = d->head;
	new_node->prev = d->tail;
	d->head = new_node;
}

void InsertBeforeKey(DoublyLL *d, int key, int data)
{
	if(d->head == NULL)
	{
		printf("The element %d is not present in the list\n", key);
		return ;
	}
	Node *curr = d->head;
	while(curr->data != key && curr->next != d->head)
		curr = curr->next;
	if(curr->data != key)
	{
		printf("The element %d is not present in the list\n", key);
		return ;
	}
	if(curr == d->head)
	{
		InsertAtHead(d, data);
		return ;
	}
	Node *new_node = newNode(data);
	Node *prev = curr->prev;
	new_node->next = curr;
	new_node->prev = prev;
	curr->prev = new_node;
	prev->next = new_node;
}

void Print(DoublyLL *d)
{
	if(d->head == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	printf("The elements in the list are : ");
	Node *n = d->head;
	while(n->next != d->head)
	{
		printf("%d ", n->data);
		n = n->next;
	}
	printf("%d ", n->data);
	printf("\n");
}

void freeList(DoublyLL *d)
{
	Node *n = d->head, *temp;
	if(n == NULL)
		return ;
	while(n->next != d->head)
	{	
		temp = n;
		n = n->next;
		free(temp);
	}
	free(n);
}

int main()
{
	int opt;
	DoublyLL *d = newDLL();
	do{
		printf("\nMenu : \n");
		printf("1. Insert At Head\n");
		printf("2. Insert Before a given key value\n");
		printf("3. Exit\n");
		printf("Enter option : ");
		scanf("%d", &opt);
		if(opt == 1)
		{
			int data;
			printf("Enter a value for insertion : ");
			scanf("%d", &data);
			InsertAtHead(d, data);
		}
		else if(opt == 2)
		{
			int data, key;
			printf("Enter a key value and a value for insertion : ");
			scanf("%d%d", &key, &data);
			InsertBeforeKey(d, key, data);
		}
		Print(d);
	}while(opt != 3);
	freeList(d);
	free(d);
	return 0;
}
