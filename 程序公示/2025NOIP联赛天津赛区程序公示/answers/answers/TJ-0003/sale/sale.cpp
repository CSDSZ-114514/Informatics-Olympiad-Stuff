#include <bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m;
long long a[5005],c[5005],dp[5005];
int ans;
struct node
{
	long long v,cost,id;
	double val;
	bool operator <(node other)
	{
		return (val!=other.val)?(val>other.val):((v!=other.v)?(v>other.v):(id<other.id));
	}
};
node d[5005];
void dfs(int step)
{
	if(step>n)
	{
		long long opti=0;
		for(int i=1;i<=m;i++)
			dp[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=m;j>=c[i];j--)
				dp[j]=max(dp[j],dp[j-c[i]]+a[i]);
		for(int i=1;i<=m;i++)
			opti=max(opti,dp[i]);
		for(int i=1;i<=n;i++)
			d[i]={a[i],c[i],i,1.0*a[i]/c[i]};
		sort(d+1,d+n+1);
		int mm=m;
		long long sum=0;
		for(int i=1;i<=n;i++)
			if(mm>=d[i].cost)
			{
				sum+=d[i].v;
				mm-=d[i].cost;
			}
		if(sum==opti)
			ans++;
		return ;
	}
	c[step]=1;
	dfs(step+1);
	c[step]=2;
	dfs(step+1);
}
int mian()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ans=0;
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}
namespace B
{
int n,m,a[5005],ans;
const int p=998244353;
int f[5005],inv[5005],invf[5005];
inline int c(int n,int m)//n里选m个
{
	return 1ll*f[n]*invf[m]%p*invf[n-m]%p;
}
int mainB()//特殊性质B
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]=-a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		a[i]=-a[i];
	int ans=1;
	for(int i=1;i<=n;i++)
		ans=ans*2%p;
	f[0]=inv[0]=inv[1]=invf[0]=1;
	for(int i=1;i<=n;i++)
		f[i]=1ll*f[i-1]*i%p;
	for(int i=2;i<=n;i++)
		inv[i]=1ll*(p-p/i)*inv[p%i]%p;
	for(int i=1;i<=n;i++)
		invf[i]=1ll*invf[i-1]*inv[i]%p;
	for(int i=1;i<=n;i++)
	{
		//计算1数
		//应该花m-1元
		int j=2*i-m+1;
		int k=m-1-i;
		if(j>=1&&k>=1&&j<=i&&k<=i&&k<=m&&j<=m)
		{
			for(int s=i;s>=1;s--)
			{
				if(a[s]!=a[i])
				{
					if(k<=s)
						ans=(ans-c(s,k)+p)%p;
					break;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
};
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int ID,t;
	cin>>ID>>t;
	for(int i=1;i<=t;i++)
		mian();
	return 0;
}
