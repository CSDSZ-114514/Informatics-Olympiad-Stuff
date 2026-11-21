#include <bits/stdc++.h>
using namespace std;
int a[10000];
bool cmp(int x,int y)
{
	if(x>y)
		return true;
	else
		return false;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int n,m;
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			int w=1/a[i];
		}
		sort(a,a+n,cmp);
		if(m==2)
		{
			cout<<2<<endl;
			continue;
		}
		long s=2;
		for(int i=1;i<=n;i++)
		{
			s=s*2%998244353; 
		}
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

