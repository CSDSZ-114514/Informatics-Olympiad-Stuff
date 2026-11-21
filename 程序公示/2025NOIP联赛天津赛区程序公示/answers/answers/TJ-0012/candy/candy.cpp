#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=100005;
struct no{
	int x,y,id;
	bool operator < (const no b) const{
		if(x<b.x)	return 1;
		else if(x>b.x)	return 0;
		else return y<b.y;
	}
}a[N];
int b[N];
inline int get(int i)
{
	if(a[i].id==i)
		i++;
	return i;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int i,tmp,n,cnt=0,id;
	ll m,idx,s=LONG_LONG_MAX,ans=0,sum=0;
	scanf("%d%lld",&n,&m);
	for(i=1;i<=n;i++)
    {
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
		if(a[i].x+a[i].y<s)
		{
			s=a[i].x+a[i].y;
			idx=a[i].x,id=i;
		}
		else if(a[i].x+a[i].y==s)
		{
			if(a[i].x<idx)
				idx=a[i].x,id=i;
		}
    }
    sort(a+1,a+1+n);
    a[n+1].x=a[n+1].y=1e9;
    for(i=1;i<=n;i++)
	{
		if(id==a[i].id)
			continue;
		tmp=get(i+1);
		if(a[i].x+a[tmp].x>=s||a[i].x>=idx)
			break;
		if(m<a[i].x)
			break;
		m-=a[i].x;
		ans++;
		b[++cnt]=a[i].y;
	}
	ans+=m/s*2;
	m%=s;
	while(i<=n)
	{
		if(a[i].id==id)
		{
			i++;
			continue;
		}
		b[++cnt]=a[i].x;
		i++;
	}
	b[++cnt]=idx;
	sort(b+1,b+1+cnt);
	for(i=1;i<=cnt;i++)
	{
		if(m>=b[i])
		{
			m-=b[i];
			ans++;
		}
		else
			break;
	}
	printf("%lld",ans);
	return 0;
}
