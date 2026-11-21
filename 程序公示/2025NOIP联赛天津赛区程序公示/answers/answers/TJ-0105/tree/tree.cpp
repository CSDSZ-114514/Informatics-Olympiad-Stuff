#include <bits/stdc++.h>
using namespace std;
long long p[10000];
long long f[10000];
long long b[10000][10000];
long long a[10000];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,s=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i];
			f[p[i]]++;
			b[p[i]][i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			a[i]=f[i];
			if(f[i]>1)
			{
				for(int i=1;i<=f[i];i++)
				{
					a[i]+=i;
				} 
			}
		}
		for(int i=1;i<=f[i];i++)
		{
			s+=a[i];
		} 
		cout<<s<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

