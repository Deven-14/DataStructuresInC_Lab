#include <stdio.h>

int fibonacci(int n)
{
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	return fibonacci(n-2) + fibonacci(n-1);
}

int main()
{
	int n;
	printf("Enter the nth number of fibonacci series : ");
	scanf("%d",&n);
	printf("Fibonacci series : ");
	for(int i=1;i<=n;++i)
	{
		int number = fibonacci(i);
		printf("%d ",number);
	}
	printf("\n");
	return 0;
}
