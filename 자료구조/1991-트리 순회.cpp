#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

typedef struct Node {
	char data;
	Node *left;
	Node *right;
}Node;

Node *nodes;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void preorder(Node *R) 
{
	printf("%c", R->data);
	if (R->left) preorder(R->left);
	if (R->right) preorder(R->right);
}
void inorder(Node *R) 
{
	if (R->left) inorder(R->left);
	printf("%c", R->data);
	if (R->right) inorder(R->right);
		
}
void postorder(Node *R)
{
	if (R->left) postorder(R->left);
	if (R->right) postorder(R->right);
	printf("%c", R->data);
}

int main() 
{
	int n, number;
	char alphabet, right_child, left_child;


	cin >> n;

	nodes = (Node*)malloc(sizeof(Node)*n);

	for (int i = 0; i < n; i++) 
	{
		cin >> alphabet >> left_child >> right_child;
		number = alphabet - 'A';
		nodes[number].data = alphabet;

		if (left_child == '.')
		{
			nodes[number].left = NULL;
		}
		else
		{
			nodes[number].left = &nodes[left_child - 'A'];
		}
		if (right_child == '.')
		{
			nodes[number].right = NULL;
		}
		else 
		{
			nodes[number].right = &nodes[right_child - 'A'];
		}
	}
	
	Node* root = nodes;

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);

	free(nodes);

	return 0;
}