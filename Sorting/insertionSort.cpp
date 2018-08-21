#include <iostream>
using namespace std;

int getMinIndex(int* a,int i,int j)
{
	// returns index of minimum element between i and j
	int minIndex = i;
	for(int k=i+1;k<=j;k++)
	{
		if(a[k]<a[minIndex])
		{
			minIndex = k;
		}
	}
	return minIndex;
}

void insertionSort(int* a,int n)
{
	// Sorts elements in a
	int minIndex;
	
	for(int i=0;i<n-1;i++)
	{
		minIndex = getMinIndex(a,i,n-1);
		swap(a[i],a[minIndex]);
	}
}

void printArray(int* a,int n)
{
	for(int i=0;i<n;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void check(int* in,int* ex,int n, int testCaseNo)
{
	int bResult = true;
	
	for(int i=0;i<n;i++)
	{
		if(in[i]!=ex[i])
		{
			cout << "Test case "<< testCaseNo <<" FAILED" << endl;
			bResult = false;
			break;
		}
	}
	if(bResult)
	{
		cout << "Test case "<< testCaseNo <<" PASSED" << endl;	
	}
}

void RunTests_InsertionSort()
{
	// tests insertionSort
	
	int n;
	int testCaseNo = 0;
	
	// test case1
	int in1[] = {1};
	int ex1[] = {1};
	n = sizeof(in1)/sizeof(int);
	insertionSort(in1,n);
	check(in1,ex1,n,++testCaseNo);
	
	// test case2
	int in2[] = {3,2,1};
	int ex2[] = {1,2,3};
	n = sizeof(in2)/sizeof(int);
	insertionSort(in2,n);
	check(in2,ex2,n,++testCaseNo);
	
}

int main()
{
	int a[] = {2,1,4,6,5};
	int n = sizeof(a)/sizeof(int);
	
	printArray(a,n);
	insertionSort(a,n);
	printArray(a,n);
	
	RunTests_InsertionSort();
	
	return 0;
}
