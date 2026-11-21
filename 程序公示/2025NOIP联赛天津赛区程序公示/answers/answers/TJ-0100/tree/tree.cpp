#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<n;i++)
		{
			int a;
			cin>>a;
		}
		int sum=2*n-3+(n/3)*2;
		cout<<sum<<endl;
	}
	return 0;
} 
