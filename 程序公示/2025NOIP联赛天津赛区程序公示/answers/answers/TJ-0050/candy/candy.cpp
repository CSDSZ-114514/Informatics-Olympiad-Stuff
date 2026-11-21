#include<bits/stdc++.h>
using namespace std;

#define MAXN 100100

long long n,ans,m;
long long fa[MAXN],fb[MAXN];

int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	
	for(int i=1;i<=n;++i)
	{
		long long x,y;
		scanf("%lld %lld",&x,&y);
		fa[i]=x;
		fb[i]=x+y;
	}
	
	sort(fa+1,fa+n+1);
	sort(fb+1,fb+n+1);
	
	int i;
	for(i=1;i<=n&&m>=0;++i)
	{
		if(fa[i]*2>fb[1])
		{
			ans+=((m-m%fb[1])/fb[1])*2;
			break;
		}
		else if(fa[i]*2==fb[1])
		{
			if(m>=fa[i])
			{
				m-=fa[i];
				ans++;
			}
			ans+=((m-m%fb[1])/fb[1])*2;
			break;
		}
		else
		{
			ans++;
			m-=fa[i];
		}
	}
	
	if(m>=fa[i+1]){ans++;} 
	printf("%lld\n",ans);
	return 0;
}

