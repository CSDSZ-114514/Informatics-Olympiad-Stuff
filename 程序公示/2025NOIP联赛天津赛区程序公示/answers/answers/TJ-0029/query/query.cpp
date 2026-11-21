#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e4+5;
int n,t,c[N],M=2147483648;
int lowbit(int x){return x&-x;}
void add(int pos,int x)
{
	for(;pos<=n;pos+=lowbit(pos))c[pos]+=x;
	return ; 
}
int ask(int x)
{
	int ans=0;
	for(;x;x-=lowbit(x))ans+=c[x];
	return ans;
}
signed main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		add(i,x);
	}
	cin>>t; 
	for(int i=1,l,r;i<=t;i++)
	{
		cin>>l>>r;
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			int maxn=-INT_MAX;
			for(int k=max(1ll,j-r);k<=min(n,j+r);k++)
			{
				if(abs(k-j)>=l&&abs(k-j)<=r)
				{
					maxn=max(maxn,ask(max(j,k))-ask(min(j,k)-1));
				}
			}
			ans=ans^((maxn+M)%M);
		}
		cout<<ans<<endl;
	}
	return 0;
}
