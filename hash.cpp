#include<bits/stdc++.h>
using namespace std;

int hashFunc(string s)
{
	// it returns key of that string that is hash
	int l = s.length();
	int i,ret;
	ret=0;
	for(i=0;i<l;i++)
	{
		ret += ((i+1)*s[i]);
	}
	ret = ret%2041;
	return ret%20;
}

int findString(vector<string>hash[20],string s)
{
	int index = hashFunc(s);
	int i=0;
	while(i<hash[index].size())
	{
		if(s==hash[index][i])
		{
			return 1;
		}
		i++;
	}
	return 0;
}

int main()
{
	vector<string> hash[20];
	int i,n,index;
	string s;
	cout<<"enter n: ";
	cin>>n;
	for(i=0;i<n;i++){
		cin>>s;
		index = hashFunc(s);
		hash[index].push_back(s);
	}
	cout<<"enter string: ";
	cin>>s;
	while(s!="-1")
	{
		if(findString(hash,s)==1)
		{
			cout<<s<<" string found\n";
		}else
		{
			cout<<"not found\n";
		}
	cin>>s;		
	}
	return 0;
}
