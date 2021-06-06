#include <stdio.h>
#include <stdlib.h>

struct result
{
	int n;
	int *pos;
	int capacity;
};
typedef struct result Result;

Result search(int n,int a[],int ele)
{
	Result r;
	r.n=0;
	r.capacity=1;
	r.pos=(int*)malloc(r.capacity*sizeof(int));
	for(int i=0;i<n;++i)
	{
		if(a[i]==ele)
		{
			r.pos[r.n++]=i+1;
			if(r.n==r.capacity)
			{
				r.capacity=r.n*2;
				r.pos=(int*)realloc(r.pos,r.capacity*sizeof(int));
			}
		}
	}
	return r;	
}

int main()
{
	int n,searchEle;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements\n");
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	printf("Enter the search element\n");
	scanf("%d",&searchEle);
	Result r;
	r=search(n,a,searchEle);
	printf("The pos are:\n");
	for(int i=0;i<r.n;++i)
		printf("%d ",r.pos[i]);
	printf("\n");
	free(r.pos);
	return 0;
}
