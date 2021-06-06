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

int noOfLeafNodes(Node *root) // using preOrder traversal
{
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return 1;
	return (noOfLeafNodes(root->left) + noOfLeafNodes(root->right)); // will work as preOrder
}

int noOfParentNodes(Node *root)
{
	if(root == NULL)
		return 0;
	if(root->left != NULL || root->right !=NULL) // excludes leaf notes
		return (1 + noOfParentNodes(root->left) + noOfParentNodes(root->right));
	return 0;
}

void preOrder(Node *root)
{
	if(root == NULL)
		return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node *root)
{
	if(root == NULL)
		return;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void postOrder(Node *root)
{
	if(root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
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
	int n;
	printf("Enter the number of elements to be inserted : ");
	scanf("%d",&n);
	int data;
	printf("\nEnter the elements : ");
	for(int i = 0; i < n; ++i)
	{
		scanf("%d",&data);
		root = insert(root, data);
	}
	printf("\nPreOrder traversal : ");
	preOrder(root);
	printf("\n\nInOrder traversal : ");
	inOrder(root);
	printf("\n\nPostOrder traversal : ");
	postOrder(root);
	printf("\n\nModification 1 : \n");
	printf("Number of leaf nodes in the binary search tree : %d\n", noOfLeafNodes(root));
	printf("\nModification 2 : \n");
	printf("Number of parent nodes in the binary search tree : %d\n", noOfParentNodes(root));	
	postOrderFree(root);
	return 0;
}
