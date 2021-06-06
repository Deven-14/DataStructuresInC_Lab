#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	int ht;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

Node* newNode(int data)
{
	Node *n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->ht = 0;//considering height of a single node as 0 and not 1
	n->left = NULL;
	n->right = NULL;
	return n;
}

int maxHeight(Node *lnode, Node *rnode)
{
	int lh = (lnode != NULL)? lnode->ht : -1;//considering ht of null tree as -1 and not 0
	int rh = (rnode != NULL)? rnode->ht : -1;//will work same if considered as 0 also
	return (lh > rh)? lh : rh;
}

int balanceFactor(Node *root)
{
	int lh = (root->left != NULL)? root->left->ht : -1;
	int rh = (root->right != NULL)? root->right->ht : -1;
	return (lh - rh);
}

Node* leftRotate(Node *root)
{
	Node *lnode = root;
	root = root->right;
	lnode->right = root->left;
	root->left = lnode;
	lnode->ht = maxHeight(lnode->left, lnode->right) + 1;
	root->ht = maxHeight(root->left, root->right) + 1;
	return root;
}

Node* rightRotate(Node *root)
{
	Node *rnode = root;
	root = root->left;
	rnode->left = root->right;
	root->right = rnode;
	rnode->ht = maxHeight(rnode->left, rnode->right) + 1;
	root->ht = maxHeight(root->left, root->right) + 1;
	return root;
}

Node* reBalance(Node *root)
{
	int bf = balanceFactor(root);
	if(bf == 2)
	{
		if(balanceFactor(root->left) == -1)
			root->left = leftRotate(root->left);
		root = rightRotate(root);
	}
	else if(bf == -2)
	{
		if(balanceFactor(root->right) == 1)
			root->right = rightRotate(root->right);
		root = leftRotate(root);
	}
	return root;
}

Node* insert(Node *root, int data)
{
	if(root == NULL)
		return newNode(data);
	else if(data < root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);
	root->ht = maxHeight(root->left, root->right) + 1;
	root = reBalance(root);
	return root;
}

void inOrder(Node *root)
{
	if(root == NULL)
		return ;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void preOrder(Node *root)
{
	if(root == NULL)
		return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(Node *root)
{
	if(root == NULL)
		return ;
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
	printf("\nPreOrder traversal : ");
	preOrder(root);
	printf("\nPostOrder traversal : ");
	postOrder(root);
	postOrderFree(root);
	printf("\n");
	return 0;
}
