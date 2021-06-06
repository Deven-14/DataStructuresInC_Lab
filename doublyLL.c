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
	n->prev = n->next = NULL;
	return n;
}

Node* InsertAtHead(Node *head, int data)
{
	Node *new_node = newNode(data);
	if(head == NULL)//coz we have to do head->prev, if head not present then we can't do****
		return new_node;
	head->prev = new_node;
	new_node->next = head;
	head = new_node;
	return head;
}

Node* InsertAfterKey(Node *head, int key, int data)
{
	if(head == NULL)
		return NULL;
	Node *curr = head;
	while(curr != NULL && curr->data != key)
		curr = curr->next;
	if(curr == NULL)
	{
		printf("The element %d is not present in the list\n", key);
		return head;
	}
	Node *new_node = newNode(data);
	Node *next = curr->next;
	curr->next = new_node;
	next->prev = new_node;
	new_node->next = next;
	new_node->prev = curr;
	return head;
}

Node* DeleteMiddleNode(Node *head)
{
	if(head == NULL)
		return NULL;
	Node *slow = head, *fast = head;
	while(slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	if(slow == head)//for only one node
	{
		Node *temp = head;
		head = NULL;
		free(temp);
	}
	else if(slow->next == NULL)//last node (happens when there are 2 elements)
	{
		Node *temp = slow;
		slow = slow->prev;
		slow->next = NULL;
		free(temp);
	}
	else
	{
		Node *prev = slow->prev;
		Node *next = slow->next;
		prev->next = next;
		next->prev = prev;
		free(slow);
	}
	return head;
}

Node* DeleteTail(Node *head)
{
	if(head == NULL)
		return NULL;
	Node *curr = head;
	while(curr->next != NULL)
		curr = curr->next;
	if(curr == head)//coz u can't do curr->next = NULL***************
	{
		free(head);
		return NULL;
	}
	Node *temp = curr;
	curr = curr->prev;
	curr->next = NULL;
	free(temp);
	return head;
}
void Print(Node *head)
{
	if(head == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	printf("The elements in the list are : ");
	Node *n = head;
	while(n != NULL)
	{
		printf("%d ", n->data);
		n = n->next;
	}
	printf("\n");
}

void PrintReverse(Node *head)
{
	if(head == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	printf("The elements in the list in reverse order are : ");
	Node *n = head;
	while(n->next != NULL)
		n = n->next;
	while(n != NULL)
	{
		printf("%d ", n->data);
		n = n->prev;
	}
	printf("\n");
}


void freeList(Node *head)
{
	Node *n = head, *temp;
	while(n != NULL)
	{
		temp = n;
		n = n->next;
		free(temp);
	}
}

int main()
{
	//FOR CIRCULAR DLL, JUST CONNENT THE LAST ELEMENTS LINK TO THE FIRST NODE AND THE HEAD->PREV TO THE TAIL AND THEN WHERE EVER curr!=null is there it'll change to curr!=head, i.e instead of null it'll be head and u can reach tail faster using the circular queues
	int opt;
	Node *head = NULL;
	do
	{
		printf("\nMenu : \n");
		printf("1. Insert At Head\n");
		printf("2. Insert After a given key value\n");
		printf("3. Delete Tail node\n");
		printf("4. Delete the middle node\n");
		printf("5. Print the list in reverse order\n");
		printf("6. Exit\n");
		printf("Enter option : ");
		scanf("%d", &opt);
		if(opt == 1)
		{
			int data;
			printf("Enter a value for insertion : ");
			scanf("%d", &data);
			head = InsertAtHead(head, data);
		}
		else if(opt == 2)
		{
			int data, key;
			printf("Enter a key value and a value for insertion : ");
			scanf("%d%d", &key, &data);
			head = InsertAfterKey(head, key, data);
		}
		else if(opt == 3)
			head = DeleteTail(head);
		else if(opt == 4)
			head = DeleteMiddleNode(head);
		else if(opt == 5)
			PrintReverse(head);
		Print(head);
	}while(opt != 6);
	freeList(head);
	return 0;
}
