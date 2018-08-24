#include <iostream>
using namespace std;

void printArray(int* a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void sorts012(int* a, int low, int high)
{
	// sorts an array of 0,1,2 using 3 way partitioning
	// assumes array contains eithe 0,1 or 2 not anything else
	
	int i = low;
	while(i<=high)
	{
		if(a[i]==1)
		{
			i++;
		}
		else if(a[i]==0)
		{
			swap(a[i],a[low]);
			low++;
			i++;
		}
		else //2
		{
			swap(a[i],a[high]);
			high--;
		}
	}
}

int main()
{
	//int a[] = {0,1,0,2,1,0,2,1};
	//int a[] = {0};
	//int a[] = {2,1};
	//int a[] = {2,1,0};
	int a[] = {1,1,2,2,2,0,0,0,0,0,0,0,1};
	
	int n = sizeof(a)/sizeof(int);
	
	printArray(a,n);
	sorts012(a,0,n-1);
	printArray(a,n);
	
	return 0;
}
