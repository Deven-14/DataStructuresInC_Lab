#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter the number of integers : ");
	scanf("%d",&n);
	int *a=(int*)malloc(n*sizeof(int));//or calloc
	printf("Enter the integers : ");
	for(int i=0;i<n;++i)
		scanf("%d",(a+i));
	printf("The array elements are : ");
	for(int i=0;i<n;++i)
		printf("%d ",*(a+i));
	printf("\n");
	free(a);
	return 0;
}
