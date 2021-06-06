#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

Node* newNode(int data)
{
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

Node* insert(Node *root, int data)
{
	if(root == NULL)
		return newNode(data);
	else if(data < root->data)
		root->left = insert(root->left, data);
	else if(data >= root->data) // adding duplicates to the right
		root->right = insert(root->right, data);
	return root;
}

//iterative method
/*
Node* insert(Node *root, int data)
{
	if(root == NULL)
		return newNode(data);
	Node *curr = root, *prev = NULL;
	while(curr!=NULL)
	{
		prev = curr;
		if(data < curr->data)
			curr = curr->left;
		else if(data >= curr->data) // adding dupluicates to the right
			curr = curr->right;
	}
	if(data < prev->data)
		prev->left = newNode(data);
	else
		prev->right = newNode(data);
	return root;
}
*/

Node* findMin(Node *root)
{
	if(root == NULL)
		return NULL;
	Node *curr = root;
	while(curr->left != NULL)
		curr = curr->left;
	return curr;
}

Node* Delete(Node *root, int key)
{
	if(root == NULL)
		return NULL;
	else if(key < root->data)
		root->left = Delete(root->left, key);
	else if(key > root->data)
		root->right = Delete(root->right, key);
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if(root->left == NULL)
		{
			Node *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL)
		{
			Node *temp = root;
			root = root->left;
			free(temp);
		}
		else
		{
			Node *temp = findMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

//iterative method
/*Node* Delete2(Node *root, int key)
{
	if(root == NULL)
		return NULL;
	Node *curr = root, *prev = NULL;
	while(curr!=NULL && curr->data != key)
	{
		prev = curr;
		if(key < curr->data)
			curr = curr->left;
		else if(key > curr->data) // adding dupluicates to the right
			curr = curr->right;
	}
	if(curr == NULL)
		return root;
	if(curr->left == NULL && curr->right == NULL)
	{
	    if(prev == NULL)
	        root = NULL;
		else if(prev->left == curr)
			prev->left = NULL;
		else
			prev->right = NULL;
		free(curr);
	}
	else if(curr->left == NULL)
	{
	    if(prev == NULL)
	        root = curr->right;//*************root and not curr= curr->right, coz the value of the pointer is changing, i.e is the address
		else if(prev->left == curr)
			prev->left = curr->right;
		else
			prev->right = curr->right;
		free(curr);
	}
	else if(curr->right == NULL)
	{
	    if(prev == NULL)
	        root = curr->left;
		else if(prev->left == curr)
			prev->left = curr->left;
		else
			prev->right = curr->left;
		free(curr);
	}
	else
	{
		Node *temp = curr->right, *par = curr;//******************************
		while(temp->left != NULL)
		{
			par = temp;
			temp = temp->left;
		}
		curr->data = temp->data;
		if(par->left == temp)//coz, par could be curr and here par->right == temp
			par->left = temp->right;
		else
			par->right = temp->right;//temp->right and not null, coz it can have greater eles
		free(temp);
	}
	return root;
}*/
		
void inOrder(Node *root)
{
	if(root == NULL)
		return;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void postOrderFree(Node *root)
{
	if(root == NULL)
		return ;
	postOrderFree(root->left);
	postOrderFree(root->right);
	free(root);
}

int main()
{
	Node *root = NULL;
	int option;
	do
	{
		printf("\nMenu :\n");
		printf("1. Insert a value in bst\n");
		printf("2. Delete a value from bst\n");
		printf("3. Exit\n");
		printf("Enter option : ");
		scanf("%d",&option);
		if(option==1)
		{
			int data;
			printf("Enter the data to be inserted : ");
			scanf("%d",&data);
			root = insert(root, data);
		}
		else if(option==2)
		{
			int data;
			printf("Enter the data to be deleted : ");
			scanf("%d",&data);
			root = Delete(root, data);	
		}
		printf("InOrder traversal : ");
		inOrder(root);
		printf("\n");
	}while(option!=3);
	postOrderFree(root);
	printf("\n");
	return 0;
}
