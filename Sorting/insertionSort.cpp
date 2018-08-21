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

void RunTest_InsetionSort()
{
	// tests insertionSort
}

int main()
{
	int a[] = {2,1,4,6,5};
	int n = sizeof(a)/sizeof(int);
	
	printArray(a,n);
	insertionSort(a,n);
	printArray(a,n);
	
	RunTest_InsetionSort();
	
	return 0;
}
