#include<bits/stdc++.h>
using namespace std;
//triplet represenatation
int main()
{
	int m,n;
	int i,j;
	cout<<"enter m and n: ";
	cin>>n>>m;
	int arr[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	int nonZeroCount=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(arr[i][j]!=0)
			{
				nonZeroCount++;
			}
		}
	}
	int triplet[nonZeroCount+1][3];
	triplet[0][0] = n;//first entry is no. of rows
	triplet[0][1] = m;//no. of cols
	triplet[0][2] = nonZeroCount;//no. of non zero vals
	
	int k=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(arr[i][j]!=0)
			{
			  triplet[k][0] = i;
			  triplet[k][1] = j;
			  triplet[k][2] = arr[i][j];
			  k++;
			}
		}
	}	
	
	cout<<"Rows"<<"\t"<<"Cols"<<"\t"<<"values\n";
	for(i=0;i<=nonZeroCount;i++)
	{
		cout<<triplet[i][0]<<"\t"<<triplet[i][1]<<"\t"<<triplet[i][2]<<"\n";
	}
	
	return 0;
}
