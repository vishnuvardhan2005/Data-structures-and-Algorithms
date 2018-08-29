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

void insert(listNode** head, int data)
{
	// inserts data in the beg
	listNode* sr = new listNode(data, *head);
	*head = sr;
}

void print(listNode* head)
{
	listNode* sr = head;
	while(sr!=NULL)
	{
		cout << sr->data << " ";
		sr = sr->next;
	}
	cout << endl;
}

void destroy(listNode* head)
{
	listNode* sr = head;
	while(sr!=NULL)
	{
		head = head->next;
		delete sr;
		sr = head;
	}
}

int main()
{
	listNode* head =  NULL;
	
	insert(&head, 10);
	insert(&head, 1);
	insert(&head, 20);
	insert(&head, 3);
	insert(&head, 5);
	
	print(head);
	
	destroy(head);
	
	return 0;
}
