#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

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
		return -1;
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

int performOperation(char Operator,int operand1,int operand2)
{
	switch(Operator)
	{
		case '+' : return (operand1 + operand2);
		case '-' : return (operand1 - operand2);
		case '*' : return (operand1 * operand2);
		case '/' : return (operand1 / operand2);
		case '^' : return (pow(operand1,operand2));
	}
}

int postfixEvaluation(char *postfix)
{
	int len = strlen(postfix);
	Stack *s = newStack();
	int result;
	for(int i=0;i<len;++i)
	{
		 if(isdigit(postfix[i]))
		 	push(s,postfix[i]-'0');
		 else
		 {
		 	int operand2=pop(s);
		 	int operand1=pop(s);
		 	int resultantOperand=performOperation(postfix[i],operand1,operand2);
		 	push(s,resultantOperand);
		}
	}
	result=pop(s);
	if(!isEmpty(s))
		freeStack(s);
	free(s);
	return result;
}

int main()
{
	//gcc postfixEvaluation.c -lm  , do this as math library needs linkage
	char *postfix = (char*)malloc(100*sizeof(char));
	printf("Enter the Postfix Expression : ");
	scanf("%s",postfix);
	postfix = (char*)realloc(postfix,(strlen(postfix) + 1) * sizeof(char));
	int result = postfixEvaluation(postfix);
	printf("Result of the Postfix Expression = %d\n",result);
	free(postfix);
	return 0;
}
