#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	char data[4];
	struct node *left;
	struct node *right;
};
typedef struct node Node;

Node* insert(Node *root, char data[])
{
	if(root == NULL)
	{
		Node *n = (Node*)malloc(sizeof(Node));
		strcpy(n->data, data);
		n->left = n->right = NULL;
		return n;
	}
	else if(strcmp(data, root->data) < 0)
		root->left = insert(root->left, data);
	else if(strcmp(data, root->data) >= 0)
		root->right = insert(root->right, data);
	return root;
}
		
void inOrder(Node *root)
{
	if(root == NULL)
		return;
	inOrder(root->left);
	printf("%s, ", root->data);
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
	char data[][4] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
	for(int i = 0; i < 12; ++i)
		root = insert(root, data[i]);
	printf("Inorder : ");
	inOrder(root);
	postOrderFree(root);
	printf("\n");
	return 0;
}
