#include <iostream>
using namespace std;

int subsetSum(int* a,int n,int s)
{
	// Returns true if exists a subset whose sum is s
	//
	bool m[n+1][s+1];
	
	for(int i=0;i<=n;i++)
	{
		m[i][0] = true;
	}
	for(int i=1;i<=s;i++)
	{
		m[0][i] = false;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s;j++)
		{
			if(j-a[i-1] >=0)
			{
				m[i][j] = m[i-1][j] || m[i-1][j-a[i-1]];
			}
			else
			{
				m[i][j] = m[i-1][j];
			}
		}
	}
	
	return m[n][s];
}

int main()
{
	int a[] = {1,5,2};
	int n = sizeof(a)/sizeof(int);
	
	cout << subsetSum(a,n,4) << endl;
	cout << subsetSum(a,n,7) << endl;
	cout << subsetSum(a,n,8) << endl;
	cout << subsetSum(a,n,10) << endl;
	
	return 0;
}
