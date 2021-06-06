#include <stdio.h>

struct patient
{
	char name[25];
	int age;
	char bloodGrp[4];
	char symptoms[100];
	char address[100];
};
typedef struct patient Patient;

Patient input_data_of_a_patient()
{
	Patient p;
	printf("Name : ");
	scanf("%s",p.name);
	printf("Age : ");
	scanf("%d",&p.age);
	printf("Blood Group : ");
	scanf("%s",p.bloodGrp);
	printf("Symptoms(Enter in a single line using commas) : ");
	scanf("%s",p.symptoms);
	printf("Address : ");
	scanf("%s",p.address);
	return p;
}

void print_patient_details(Patient p)
{
	printf("Name : %s\nAge : %d\nBlood Group : %s\n",p.name,p.age,p.bloodGrp);
	printf("Symptoms : %s\nAddress : %s\n",p.symptoms,p.address);
}

int main()
{
	int n;
	printf("Enter the number of patients : \n");
	scanf("%d",&n);
	Patient p[n];
	for(int i=0;i<n;++i){
		printf("\nEnter the data of patient %d\n",i+1);
		p[i]=input_data_of_a_patient();
		printf("\nPatient %d details :\n",i+1);
		print_patient_details(p[i]);
	}
	return 0;
}

