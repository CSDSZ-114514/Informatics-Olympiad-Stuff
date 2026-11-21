//1-5、7-12、14-20 
//求部分分满分(@__@)/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define Pair pair<int,int>
const int N=5e4+10;
const ll MOD=998244353;
int a[N];
ll kkk(int x)
{
	ll num=1; 
	while(x--)
	{
		num*=2;
		num%=MOD;
	}
	return num;
}
struct node
{
	int w,t;
	db p;
	bool operator<(const node &cmp)const
	{
		return p>cmp.p;
	}
}s[N];
int vis[N];
bool check(int n,int m)
{
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++)s[i].p=1.0*a[i]/(s[i].t*1.0),s[i].w=a[i];
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++)if(m>=s[i].t)
	{
		m-=s[i].t;
		vis[i]=1;
	}
	for(int x=1;x<=n;x++)if(vis[x])
	{
		for(int y=x+1;y<=n;y++)if(!vis[y])
		{
			for(int z=y+1;z<=n;z++)if(vis[z])
			{
				if(s[x].w+s[z].w<s[y].w)return false;
			}
		}
	}
	return true;
}
ll sum;
void dfs(int dep,int n,int m)
{
	if(dep==n+1)
	{
		if(check(n,m))sum++;
		sum%=MOD;
		return ;
	}
	s[dep].t=1;
	dfs(dep+1,n,m);
	s[dep].t=2;
	dfs(dep+1,n,m);
}
ll hhh(int n)
{
	ll num=0;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)if(a[i]*2>a[n])num++;
	for(int i=1;i<n;i++)if(a[i]*2>a[n])
	{
		for(int j=1;j<n;j++)if(a[i]+a[j]<a[n])num++;
	}
	num%=MOD;
	return (MOD+kkk(n)-num)%MOD;
}
ll jc(int x)
{
	ll p=1;
	for(int k=2;k<=x;k++)p=(p*k)%MOD;
	return p;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		if(m==2*n-1||c==18||c==16){//ok
			ll ans=kkk(n);
			printf("%lld\n",ans);
			continue;
		}
		if(m==2){
			ll ans=hhh(n);
			printf("%lld\n",ans);
			continue;
		}
		if((c<=12&&c>=10)||(c>=19&&c<=20)){
			ll ans=kkk(n);
			for(int i=1;i<n;i++)if(m>i&&m<i+(n-i)*2&&(m-i)%2==1)
			{
				int j=(m-i)/2;
				ll p=jc((m-i)/2-1)*jc(n-2);
				p%=MOD;
				ans=(ans+MOD-p)%MOD;
			}
			printf("%lld\n",ans);
			continue;
		}
		if(c==17){//ok
			ll ans=kkk(n);
			sort(a+1,a+n+1);
			if(a[1]!=a[2]&&a[1]*2>a[2])ans--;
			printf("%lld\n",ans);
			continue;
		}
		if(c<=5){
			dfs(1,n,m);
			printf("%lld\n",sum);
			continue;
		}
		printf("0");
	}
	return 0;
}
