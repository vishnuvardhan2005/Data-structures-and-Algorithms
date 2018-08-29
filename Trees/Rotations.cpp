/* 
This program demostrates the rotations to make a tree balanced
*/

#include <iostream>
using namespace std;

// Tree node
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

Node* leftRotate(Node* z)
{
	// Performs a Left rotating at z
	Node* y = z->right;
	Node* x = y->right;
	
	z->right = y->left;
	y->left = z;
	
	return y;	
}

int getHeight(Node* sr)
{
	// base case
	if(sr==NULL)
	{
		return 0;
	}
	
	return 1+max(getHeight(sr->left), getHeight(sr->right));
}

void printWithBalanceFactors(Node* sr)
{
	// prints the tree in-order along with balance factor of the node
	if(sr!=NULL)
	{
		int bf;
		
		printWithBalanceFactors(sr->left);
		bf = getHeight(sr->left) - getHeight(sr->right);
		cout << sr->data << " bf = " << bf << endl;
		printWithBalanceFactors(sr->right);
	}
}

int main()
{
	Node* root = NULL;
	root = new Node(1);
	root->right = new Node(2);
	root->right->right = new Node(3);
	
	printWithBalanceFactors(root);
	cout << endl;
	
	// After inserting nodes 1,2,3 tree becomes RightRight imbalanced and hence it has to be left rotate to make it balance
	root = leftRotate(root);
	
	printWithBalanceFactors(root);
	cout << endl;
	
	return 0;
}
