#include <stdio.h>
#define max 5

int top=-1;
//const int max=10;//********************
int stack[max];

void push(int data)
{
	if(top==max-1)
		printf("Stack Overflow\n");
	else
		stack[++top]=data;
}

int pop()
{
	int item=-1;
	if(top==-1)
		printf("Stack Underflow\n");
	else
	{
		item=stack[top--];
		printf("%d is poped from the stack\n",item);
	}
	return item;
}

int isEmpty()
{
	return top==-1;
}

int isFull()
{
	return top==max-1;
}

int peek()
{
	int item=-1;
	if(top!=-1)
	{
		item=stack[top];
		printf("%d is the top element\n",item);
	}
	else
		printf("Underflow\n");
	return item;
}

int peep(int pos)
{
	int item=-1;
	if(top!=-1 && pos<=top+1)
	{
		item=stack[top-pos+1];
		printf("%d is the element at position(from top) %d\n",item,pos);
	}
	else
		printf("Position %d does not exist in the stack \n",pos);
	return item;
}

void printStack()
{
	if(top==-1)
		printf("Stack is empty(underflow)\n");
	else
	{
		printf("The Stack is : ");
		for(int i=top;i>=0;--i)
			printf("%d ",stack[i]);
		printf("\n");
	}
}

int main()
{
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
			push(item);
		}
		else if(opt==2)
			pop();	
		else if(opt==3)
			peek();
		else if(opt==4)
		{
			int pos;
			printf("Enter position : ");
			scanf("%d",&pos);
			peep(pos);
		}
		printStack();
	}while(opt!=5);
	return 0;
}
