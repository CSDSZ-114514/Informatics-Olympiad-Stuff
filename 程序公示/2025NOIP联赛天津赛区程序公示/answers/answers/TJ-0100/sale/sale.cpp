#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,m,ji=1;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a; 
			ji*=2;
			ji=ji%998244353;
		}
		cout<<ji<<endl;
	}
	return 0;
} 
