#include <stdio.h>
#include <stdlib.h>

struct employee
{
	char name[25];
	int age;
	char sex;
	long phoneNo;
	char address[50];
};
typedef struct employee Employee;

int main()
{
	Employee *e=(Employee*)malloc(sizeof(Employee));
	printf("Enter the employee details:\n");
	printf("Name : ");
	scanf("%s",e->name);
	printf("age : ");
	scanf("%d",&e->age);
	printf("sex(m/f) : ");
	scanf(" %c",&e->sex);
	printf("Phone number : ");
	scanf("%ld",&e->phoneNo);
	printf("Address : ");
	scanf("%s",e->address);
	printf("Employee details are : \n");
	printf("Name : %s\n",e->name);
	printf("age : %d\n",e->age);
	printf("sex(m/f) : %c\n",e->sex);
	printf("Phone number : %ld\n",e->phoneNo);
	printf("Address : %s\n",e->address);
	free(e);
	return 0;
}
