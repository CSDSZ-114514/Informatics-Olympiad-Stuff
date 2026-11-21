#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int n,q,L,R;
int a[N];
long long sum[N];
long long maxn[N];
long long ans;
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	cin>>q;
	while(q--)
	{
		cin>>L>>R;
		for(int len=L;len<=R;len++)
		{
			for(int i=1;i<=n-len+1;i++)
			{
				int j=i+len-1;
				for(int k=i;k<=j;k++) maxn[k]=max(maxn[k],sum[j]-sum[i-1]);
			}
		} 
		for(int i=1;i<=n;i++) ans^=i*maxn[i];
		cout<<ans<<endl;
	}
	return 0;
}
