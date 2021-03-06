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

int maxHeight(Node *lnode, Node *rnode)
{
	int lh = (lnode != NULL)? lnode->ht : -1;
	int rh = (rnode != NULL)? rnode->ht : -1;
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
	printf("Left Rotate %d\n", root->data);
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
	printf("Right Rotate %d\n", root->data);
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
	printf("Balance Factor of %d : %d\n", root->data, bf);
	if(bf == 2)
	{
		if(balanceFactor(root->left) == -1)
		{
			printf("Balance Factor of %d : -1\n", root->left->data);
			root->left = leftRotate(root->left);
		}
		root = rightRotate(root);
	}
	else if(bf == -2)
	{
		if(balanceFactor(root->right) == 1)
		{
			printf("Balance Factor of %d : 1\n", root->right->data);
			root->right = rightRotate(root->right);
		}
		root = leftRotate(root);
	}
	return root;
}

Node* insert(Node *root, int data)
{
	if(root == NULL)
	{
		Node *n = (Node*)malloc(sizeof(Node));
		n->data = data;
		n->ht = 0;
		n->left = NULL;
		n->right = NULL;
		printf("Entered data : %d\n", data);
		return n;
	}
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
	int data[] = {30, 31, 32, 23, 22, 28, 24, 29, 26, 27, 34, 36};
	for(int i = 0; i < 12; ++i)
	{
		root = insert(root, data[i]);
		printf("\n");
	}
	printf("Inorder traversal : ");
	inOrder(root);
	postOrderFree(root);
	printf("\n");
	return 0;
}
