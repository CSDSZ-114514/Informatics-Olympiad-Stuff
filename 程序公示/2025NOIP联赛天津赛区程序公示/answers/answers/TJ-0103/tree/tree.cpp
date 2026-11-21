#include<bits/stdc++.h>
using namespace std;
int a[100020];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int len;
	cin>>len;
	int n,m;
	for(int i=0;i<len;i++)
	{
		cin>>n>>m;
		long long num=0;
		for(int i=0;i<n-1;i++) 
		{
			cin>>a[i];
			num+=a[i];
		}
		cout<<num<<endl;
	}
	return 0;
}
