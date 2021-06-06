#include <stdio.h>

void towerOfHanoi(int n, char *source, char *destination, char *temp)
{
	if(n<=0)
		return;
	towerOfHanoi(n - 1, source, temp, destination);
	printf("Move %dth disk from %s to %s rod\n",n,source,destination);
	towerOfHanoi(n - 1, temp, destination, source);
}

int main()
{
	int n;
	char source[]="source",destination[]="destination",temp[]="temporary";
	printf("Enter number of disks to be moved from source to destination : ");
	scanf("%d",&n);
	printf("Steps : \n");
	towerOfHanoi(n, source, destination, temp);
	return 0;
}
