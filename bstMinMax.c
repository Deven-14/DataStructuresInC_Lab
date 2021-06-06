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

Node* findMin(Node *root)
{
	if(root == NULL)
		return NULL;
	Node *curr = root;
	while(curr->left != NULL)
		curr = curr->left;
	return curr;
}

Node* findMax(Node *root)
{
	if(root == NULL)
		return NULL;
	Node *curr = root;
	while(curr->right != NULL)
		curr = curr->right;
	return curr;
}
		
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
	int n;
	printf("Enter the number of nodes to be inserted : ");
	scanf("%d", &n);
	Node *root = NULL;
	printf("Enter the elements : ");
	int data;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &data);
		root = insert(root, data);
	}
	printf("Inorder traversal : ");
	inOrder(root);
	Node *min = findMin(root);
	if(min)
		printf("\nThe minimum element in the bst is : %d\n", min->data);
	else
		printf("The bst is empty\n");
	Node *max = findMax(root);
	if(max)
		printf("The maximum element in the bst is : %d\n", max->data);
	else
		printf("The bst is empty\n");
	postOrderFree(root);
	printf("\n");
	return 0;
}
