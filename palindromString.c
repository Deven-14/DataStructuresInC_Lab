#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char data;
	struct node *next;
};
typedef struct node Node;

Node* newNode(char data)
{
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	return n;
}

struct stack
{
	Node *top;
};
typedef struct stack Stack;

Stack* newStack()
{
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->top = NULL;
	return s;
}

void push(Stack *s,char data)
{
	Node *new_node = newNode(data);
	new_node->next = s->top;
	s->top = new_node;
}

void pop(Stack *s)
{
	if(s->top == NULL)
		return;
	Node *temp = s->top;
	s->top = s->top->next;
	free(temp);
}

int isEmpty(Stack *s)
{
	if(s->top == NULL)
		return 1;
	return 0;
}

int Top(Stack *s)
{
	if(s->top == NULL)
		return -1;
	return s->top->data;
}

void freeStack(Stack *s)
{
	Node *n = s->top,*temp;
	while(n != NULL)
	{
		temp = n;
		n = n->next;
		free(temp);
	}
}

int isPalindrom(char *str)
{
	Stack *s = newStack();
	int i = 0;
	int flag = 1;
	int len = strlen(str);
	for(i = 0; i < len/2; ++i)
		push(s, str[i]);
	if(len % 2 == 1)
		++i;
	for(; i < len; ++i)
	{
		if(str[i] != Top(s))
		{
			flag = 0;
			break;
		}
		pop(s);
	}
	freeStack(s);
	free(s);
	return flag;
}

int main()
{
	char *str = (char*)malloc(10000*sizeof(char));
	printf("Input string : ");
	scanf("%s",str);
	str = (char*)realloc(str,(strlen(str)+1)*sizeof(char));
	if(isPalindrom(str))
		printf("The string %s is a Palindrome\n",str);
	else
		printf("The string %s is not a Palindrome\n",str);
	free(str);
	return 0;
}
