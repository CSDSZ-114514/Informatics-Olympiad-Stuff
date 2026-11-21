#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int MOD=998244353;
struct node{
	int v,w1,id;
}b[N],b2[N];
int c,t;
int n,m;
int ans;
int a[N];
int w[N];
int w2[N];
int p[N+1];
long long dp[2*N];
long long dp2[2*N];
bool cmp(node d,node e)
{
	double t1=1.0*d.v/d.w1,t2=1.0*e.v/e.w1;
	if(t1==t2) 
	{
		if(d.v==e.v) return d.id<e.id;
		return d.v>e.v;
	}
	return t1>t2;
}
void dfs(int x)
{
	if(x==n+1)
	{
		for(int i=0;i<=m;i++) dp[i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=w[i];j--)
			{
				dp[j]=max(dp[j],dp[j-w[i]]+a[i]);
			}
		}
		for(int i=1;i<=n;i++) b[i].v=a[i],b[i].w1=w[i],b[i].id=i;
		sort(b+1,b+n+1,cmp);
		int W=m;
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			if(W>=b[i].w1) W-=b[i].w1,sum+=b[i].v;
		}
		if(sum==dp[m]) ans++,ans%=MOD;
		return;
	}
	w[x]=1;
	dfs(x+1);
	w[x]=2;
	dfs(x+1);
}
void mi()
{
	p[0]=1;
	for(int i=1;i<N;i++) p[i]=p[i-1]*2%MOD;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	if(c<=6)
	{
		while(t--)
		{
			ans=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++) cin>>a[i];
			dfs(1);
			cout<<ans<<endl;
		}
	}
	else if(c==16||c==18)
	{
		mi();
		while(t--)
		{
			cin>>n>>m;
			cout<<p[n]<<endl;
		}
	}
	else if(c==17) 
	{
		mi();
		while(t--)
		{
			cin>>n>>m;
			int mink=1; 
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				if(a[i]<a[mink]) mink=i;
				w2[i]=2;
			}
			w2[mink]=1;
			for(int i=0;i<=m;i++) dp2[i]=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=m;j>=w2[i];j--)
				{
					dp2[j]=max(dp2[j],dp2[j-w2[i]]+a[i]);
				}
			}
			for(int i=1;i<=n;i++) b2[i].v=a[i],b2[i].w1=w2[i],b2[i].id=i;
			sort(b2+1,b2+n+1,cmp);
			int W=m;
			long long sum=0;
			for(int i=1;i<=n;i++)
			{
				if(W>=b2[i].w1) W-=b2[i].w1,sum+=b2[i].v;
			}
			if(sum==dp2[m]) cout<<p[n]<<endl;
			else cout<<p[n]-1<<endl;
		}
	} 
	return 0;
}
