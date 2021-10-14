// C++ program to print bottom
// right view of binary tree
#include<bits/stdc++.h>
using namespace std;

// A binary tree node
struct Node
{
	int data;
	Node *left, *right;

	Node(int item)
	{
		data = item;
		left = right = NULL;
	}
};

// class to access maximum level
// by reference
struct _Max_level
{
	int _max_level;
};

Node *root;
_Max_level *_max = new _Max_level();

// Recursive function to print bottom
// right view of a binary tree
void bottomRightViewUtil(Node* node, int level,
						_Max_level *_max_level)
{

	// Base Case
	if (node == NULL)
		return;

	// Recur for right subtree first
	bottomRightViewUtil(node->right,
						level, _max_level);

	// If this is the last Node of its level
	if (_max_level->_max_level < level)
	{
		cout << node->data << " ";
		_max_level->_max_level = level;
	}

	// Recur for left subtree
	// with increased level
	bottomRightViewUtil(node->left,
						level + 1, _max_level);
}

// A wrapper over bottomRightViewUtil()
void bottomRightView(Node *node)
{
	bottomRightViewUtil(node, 1, _max);
}

void bottomRightView()
{
	bottomRightView(root);
}

// Driver Code
int main()
{
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->left->right = new Node(6);

	bottomRightView();
}

// This code is contributed by Arnab Kundu
