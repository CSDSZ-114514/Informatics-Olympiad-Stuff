#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define Pair pair<int,int>
const int N=1e5+10;
ll x[N],y[N];
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	ll mi=1e18;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
		mi=min(mi,x[i]+y[i]);
	}
	sort(x+1,x+n+1);
	ll ans=m/mi*2;
	ll k=ans/2;
	m-=ans/2*mi;
	for(int i=1;i<=n;i++)
	{
		if(m>=x[i])
		{
			ans++;
			m-=x[i];
		}
		else if(x[i]+x[i+1]<mi&&k>0)m+=mi-x[i]-x[i+1],k--,i++;
		else break;
	}
	printf("%lld",ans);
	return 0;
}
