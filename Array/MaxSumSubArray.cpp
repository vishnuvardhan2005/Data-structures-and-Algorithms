#include <iostream>
using namespace std;

int getMaxSumContinuousSubArray(int* a, int n)
{
	// Returns max sum of continous sub array
	// hint : think of special case when all elements are positive
	//
	int max_sum = 0;
	int curr_max_sum = 0;
	
	for(int i=0;i<n;i++)
	{
		curr_max_sum = curr_max_sum + a[i];
		if(curr_max_sum <= 0)
		{
			curr_max_sum = 0;
		}
		
		if(curr_max_sum > max_sum)
		{
			max_sum = curr_max_sum;
		}
	}
	
	return max_sum;
}

int main()
{
	int a[] = {1,2,-3,4,5,6,-9,11};
	int n = sizeof(a)/sizeof(int);
	
	cout << getMaxSumContinuousSubArray(a,n) << endl;
	
	return 0;
}
