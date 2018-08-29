#include <iostream>
using namespace std;

struct listNode
{
	int data;
	listNode* next;
	
	listNode(int data,listNode* next=NULL):data(data),next(next)
	{
		// constructor
	}
};

listNode* insert(listNode* root, int data)
{
	// inserts data in the beg
	listNode* sr = new listNode(data, root);
	return sr;
}

void print(listNode* root)
{
	listNode* sr = root;
	while(sr!=NULL)
	{
		cout << sr->data << " ";
		sr = sr->next;
	}
	cout << endl;
}

void destroy(listNode* root)
{
	listNode* sr = root;
	while(sr!=NULL)
	{
		root = root->next;
		delete sr;
		sr = root;
	}
}

int main()
{
	listNode* root =  NULL;
	
	root = insert(root, 10);
	root = insert(root, 1);
	root = insert(root, 20);
	root = insert(root, 3);
	root = insert(root, 5);
	
	print(root);
	
	destroy(root);
	
	return 0;
}
