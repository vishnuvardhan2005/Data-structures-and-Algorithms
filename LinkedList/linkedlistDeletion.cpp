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

void remove(listNode** head, int d)
{
	// Removes the node with data d
	
	listNode* sr = NULL;
	
	while((*head)!=NULL)
	{
		if((*head)->data==d)
		{
			sr = (*head);
			*head = (*head)->next;
			break;
		}
		head = &(*head)->next;
	}
	
	if(sr!=NULL)
	{
		delete sr;
	}
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
	
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 3);
	insert(&head, 2);
	insert(&head, 1);
	
	print(head);
	remove(&head, 1);
	print(head);
	remove(&head, 3);
	print(head);
	remove(&head, 5);
	print(head);
	remove(&head, 10);
	print(head);
	
	destroy(head);
	
	return 0;
}
