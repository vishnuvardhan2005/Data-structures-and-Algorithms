#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	
	Node(int data,Node* left=NULL,Node* right=NULL)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

void insert(Node*& root,int data)
{
	if(root == NULL)
	{
		root = new Node(data);
	}
	else if(root->data > data)
	{
		insert(root->left,data);
	}
	else
	{
		insert(root->right,data);
	}
}

void inorder(Node* sr)
{
	if(sr!=NULL)
	{
		inorder(sr->left);
		cout << sr->data << " " << endl;
		inorder(sr->right);
	}
}

int main()
{
	Node* root = NULL;
	insert(root, 1);
	insert(root, 2);
	insert(root, 10);
	insert(root, 5);
	insert(root, 3);
	
	inorder(root);
	
	return 0;
}
