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
	n->prev = NULL;
	n->next = NULL;
	return n;
}

Node* InsertAtHead(Node *head, int data)
{
	Node *new_node = newNode(data);
	if(head == NULL)
		return new_node;
	head->prev = new_node;
	new_node->next = head;
	head = new_node;
	return head;
}

Node* InsertBeforeKey(Node *head, int key, int data)
{
	Node *curr = head;
	while(curr != NULL && curr->data != key)
		curr = curr->next;
	if(curr == NULL)
	{
		printf("The element %d is not present in the list\n", key);
		return head;
	}
	if(curr == head)
	{
		head = InsertAtHead(head, data);
		return head;
	}
	Node *new_node = newNode(data);
	Node *prev = curr->prev;
	new_node->next = curr;
	new_node->prev = prev;
	curr->prev = new_node;
	prev->next = new_node;
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
	if(slow == head)//for one node
	{
		Node *temp = head;
		head = NULL;
		free(temp);
	}
	else if(slow->next == NULL)//for 2 nodes
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
	int opt;
	Node *head = NULL;
	do{
		printf("\nMenu : \n");
		printf("1. Insert At Head\n");
		printf("2. Insert Before a given key value\n");
		printf("3. Delete the middle node\n");
		printf("4. Exit\n");
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
			head = InsertBeforeKey(head, key, data);
		}
		else if(opt == 3)
			head = DeleteMiddleNode(head);
		Print(head);
	}while(opt != 4);
	freeList(head);
	return 0;
}
