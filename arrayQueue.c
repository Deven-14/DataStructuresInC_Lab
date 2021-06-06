#include <stdio.h>
#define max 3

int queue[max];
int front = -1;
int rear = -1;

int isEmpty()
{
	return (front==-1 && rear==-1);
}

int isFull()
{
	return (rear==max-1);
}

void enQueue(int data)
{
	if(isFull())
	{
		printf("Queue is Full\n");
		return;
	}
	if(isEmpty())
		front=rear=0;
	else
		rear++;
	queue[rear] = data;
}

void deQueue()
{
	if(isEmpty())
	{
		printf("Queue is Empty\n");
		return;
	}
	if(front==rear)//that element exists*************see isEmpty()
		front = rear = -1;
	else
		front++;
}

void printQueue()
{
	if(isEmpty())
	{
		printf("Queue is Empty\n");
		return;
	}
	printf("The Queue is : ");
	for(int i=front;i<=rear;++i)
		printf("%d ",queue[i]);
	printf("\n");
}

int Front()
{
	if(isEmpty())
	{
		printf("Queue is Empty\n");
		return -1;
	}
	return queue[front];
}

int Rear()
{
	if(isEmpty())
	{
		printf("Queue is Empty\n");
		return -1;
	}
	return queue[rear];
}

int main()
{
	int opt;
	do
	{
		printf("\nMenu : \n");
		printf("1) enQueue \n");
		printf("2) deQueue	\n");
		printf("3) Front \n");
		printf("4) Rear \n");
		printf("5) Exit\n");
		printf("Enter option : ");
		scanf("%d",&opt);
		if(opt==1)
		{
			printf("Enter the element to be enQueued : ");
			int item;
			scanf("%d",&item);
			enQueue(item);
		}
		else if(opt==2)
			deQueue();	
		else if(opt==3)
			printf("The Front element is : %d\n",Front());
		else if(opt==4)
			printf("The Rear element is : %d\n",Rear());
		printQueue();
	}while(opt!=5);
	return 0;
}
