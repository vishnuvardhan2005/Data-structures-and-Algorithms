#include <iostream>
using namespace std;

int getSum(int* a,int n)
{
	int s = 0;
	for(int i=0;i<n;i++)
	{
		s += a[i];
	}
	return s;
}

int getEquilibriumPoint(int* a,int n)
{
	// Returns the point where left sum  =  right sum
	
	// special cases
	if(n==1)
		return 1;
	
	int s = getSum(a,n);
	int equiIndex = -1;
	int leftSum = 0;
	int rightSum = 0;
	
	for(int i=1;i<n;i++)
	{
		leftSum += a[i-1];
		rightSum = s-leftSum-a[i];
		if(leftSum==rightSum)
		{
			// found
			equiIndex = i;
			break;
		}
	}
	return equiIndex+1;
}

int main()
{
	//int a[] = {1,3,5,2,2};
	//int a[] = {1};
	//int a[] = {2,2};
	int a[] = {1,6,-9,12,-1,-1};
	int n = sizeof(a)/sizeof(int);
	
	cout << getEquilibriumPoint(a,n);
	
	return 0;
}
