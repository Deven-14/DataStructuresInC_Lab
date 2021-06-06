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

struct stack
{
	Node *top;
};
typedef struct stack Stack;

Stack* newStack()
{
	Stack *s=(Stack*)malloc(sizeof(Stack));
	s->top=NULL;
	return s;
}

void push(Stack *s,int data)
{
	Node *new_node=newNode(data);
	new_node->next=s->top;
	s->top=new_node;
}

int pop(Stack *s)
{
	if(s->top==NULL)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	Node *temp=s->top;
	int data=temp->data;
	s->top=s->top->next;
	free(temp);
	return data;
}

int isEmpty(Stack *s)
{
	return s->top==NULL;
}

int peek(Stack *s)
{
	if(s->top==NULL)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	printf("%d is the top element\n",s->top->data);
	return s->top->data;
}

int peep(Stack *s,int pos)
{
	if(s->top==NULL)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	Node *n=s->top;
	int i=1;
	while(n && i<pos)
	{
		n=n->next;
		i++;
	}
	if(n==NULL)
	{
		printf("Position %d is does not exist in the stack\n",pos);
		return -1;
	}
	printf("%d is the element in the position(from top) %d\n",n->data,pos);
	return n->data;
}

void freeStack(Stack *s)
{
	Node *n=s->top,*temp;
	while(n!=NULL)
	{
		temp=n;
		n=n->next;
		free(temp);
	}
}

void printStack(Stack *s)
{
	Node *n=s->top;
	if(n==NULL)
	{
		printf("Stack Underflow\n");
		return;
	}
	printf("The stack is : ");
	while(n!=NULL)
	{
		printf("%d ",n->data);
		n=n->next;
	}
	printf("\n");
}

int main()
{
	Stack *s=newStack();
	int item,opt;
	do
	{
		printf("\nMenu : \n");
		printf("1) Push \n");
		printf("2) Pop	\n");
		printf("3) Peek \n");
		printf("4) Peep \n");
		printf("5) Exit\n");
		printf("Enter option : ");
		scanf("%d",&opt);
		if(opt==1)
		{
			printf("Enter the element to be pushed : ");
			scanf("%d",&item);
			push(s,item);
		}
		else if(opt==2)
			pop(s);	
		else if(opt==3)
			peek(s);
		else if(opt==4)
		{
			int pos;
			printf("Enter position : ");
			scanf("%d",&pos);
			peep(s,pos);
		}
		printStack(s);
	}while(opt!=5);
	freeStack(s);
	free(s);
	return 0;
}
