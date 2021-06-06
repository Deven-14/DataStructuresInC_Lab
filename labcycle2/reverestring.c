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

void push(Stack *s,char data)
{
	Node *new_node=newNode(data);
	new_node->next=s->top;
	s->top=new_node;
}

void pop(Stack *s)
{
	if(s->top==NULL)
		return;
	Node *temp=s->top;
	s->top=s->top->next;
	free(temp);
}

int isEmpty(Stack *s)
{
	if(s->top==NULL)
		return 1;
	return 0;
}

int Top(Stack *s)
{
	if(s->top==NULL)
		return -1;
	return s->top->data;
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

char* reverseString(char *str)
{
	Stack *s=newStack();
	char *revStr=(char*)malloc((strlen(str)+1)*sizeof(char));
	int i=0;
	while(str[i]!='\0')
	{
		push(s,str[i]);
		i++;
	}
	i=0;
	while(!isEmpty(s))
	{
		revStr[i]=Top(s);
		pop(s);
		i++;
	}
	revStr[i]='\0';
	free(s);
	return revStr;
}

int main()
{
	char *str=(char*)malloc(10000*sizeof(char));
	printf("Input string : ");
	scanf("%s",str);
	str=(char*)realloc(str,(strlen(str)+1)*sizeof(char));
	char *revStr;
	revStr=reverseString(str);
	printf("The reverse of the str %s is %s\n",str,revStr);
	free(revStr);
	free(str);
	return 0;
}
