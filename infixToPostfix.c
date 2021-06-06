#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

void push(Stack *s,int data)
{
	Node *new_node=newNode(data);
	new_node->next=s->top;
	s->top=new_node;
}

char pop(Stack *s)
{
	if(s->top==NULL)
		return '$';
	Node *temp=s->top;
	char data=temp->data;
	s->top=s->top->next;
	free(temp);
	return data;
}

int isEmpty(Stack *s)
{
	return s->top==NULL;
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

int isOperator(char ch)
{
	switch(ch)
	{
		case '+' :
		case '-' :
		case '*' :
		case '/' :
		case '^' : return 1;
		default : return 0;
	}
}

int isOpeningBracket(char ch)
{
	switch(ch)
	{
		case '(' :
		case '[' :
		case '{' : return 1;
		default : return 0;
	}
}

int isClosingBracket(char ch)
{
	switch(ch)
	{
		case ')' :
		case ']' :
		case '}' : return 1;
		default : return 0;
	}
}

int getPrecedenceValue(char Operator)
{
	switch(Operator)
	{
		case '+' :
		case '-' : return 1;
		case '*' :
		case '/' : return 2;
		case '^' : return 3;
		default : return 0;
	}
}

int isRightAssociative(char Operator)
{
	return (Operator == '^');
}

int hasGreaterPrecedence(char operator1,char operator2)
{
	int precedenceVal1=getPrecedenceValue(operator1);
	int precedenceVal2=getPrecedenceValue(operator2);
	if(precedenceVal1==precedenceVal2)
	{
		if(isRightAssociative(operator1))
			return 0;
		else
			return 1;
	}
	return (precedenceVal1>precedenceVal2);
}

char* infixToPostfix(char *infix)
{
	int len = strlen(infix);
	Stack *s = newStack();
	char *postfix = (char*)malloc((len + 1) * sizeof(char));
	int nPostfix = 0;
	for(int i=0;i<len;++i)
	{
		if(isdigit(infix[i]) || isalpha(infix[i]))
			postfix[nPostfix++]=infix[i];
		else if(isOperator(infix[i]))
		{
			while(!isEmpty(s) && !isOpeningBracket(infix[i]) && hasGreaterPrecedence(s->top->data,infix[i]))
				postfix[nPostfix++]=pop(s);
			push(s,infix[i]);//to push the current operator
		}
		else if(isOpeningBracket(infix[i]))
			push(s,infix[i]);
		else if(isClosingBracket(infix[i]))
		{
			while(!isEmpty(s) && !isOpeningBracket(s->top->data))
				postfix[nPostfix++]=pop(s);
			pop(s);//for opening bracket
		}		
	}
	while(!isEmpty(s))
		postfix[nPostfix++]=pop(s);
	free(s);
	return postfix;
}

int main()
{
	char *infix = (char*)malloc(100 * sizeof(char));
	printf("Enter the Infix Expression : ");
	scanf("%s",infix);
	infix = (char*)realloc(infix, (strlen(infix) + 1) * sizeof(char));
	char *postfix=infixToPostfix(infix);
	printf("The Postfix Expression is %s\n",postfix);
	free(postfix);
	free(infix);
	return 0;
}
