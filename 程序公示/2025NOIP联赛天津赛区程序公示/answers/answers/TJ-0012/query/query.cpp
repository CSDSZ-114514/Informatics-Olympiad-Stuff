#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=50005;
ll s[N];
int a[N];
struct tree{
	int l,r;
	ll maxx,lazy;
}t[N<<2];
inline int lt(int u)
{
	return u<<1;
}
inline int rt(int u)
{
	return u<<1|1;
}
const ll inf=LONG_LONG_MIN;
void build(int u,int l,int r)
{
	t[u].l=l;
	t[u].r=r;
	t[u].maxx=t[u].lazy=inf;
	if(l==r)
		return ;
	int mid=(l+r)>>1;
	build(lt(u),l,mid);
	build(rt(u),mid+1,r);
}
inline void pushdown(int u)
{
	if(t[u].lazy!=inf)
	{
		int tmp=lt(u);
		t[tmp].maxx=max(t[tmp].maxx,t[u].lazy);
		t[tmp].lazy=max(t[tmp].lazy,t[u].lazy);
		tmp=rt(u);
		t[tmp].maxx=max(t[tmp].maxx,t[u].lazy);
		t[tmp].lazy=max(t[tmp].lazy,t[u].lazy);
		t[u].lazy=inf;
	}
}
inline void pushup(int u)
{
	t[u].maxx=max(t[lt(u)].maxx,t[rt(u)].maxx);
}
void update(int u,int x,int y,ll k)
{
	if(x<=t[u].l&&t[u].r<=y)
	{
		t[u].lazy=max(t[u].lazy,k);
		t[u].maxx=max(t[u].maxx,k);
		return ;
	}
	pushdown(u);
	int mid=(t[u].l+t[u].r)>>1;
	if(x<=mid)
		update(lt(u),x,y,k);
	if(mid<y)
		update(rt(u),x,y,k);
	pushup(u);
}
ll query(int u,int k)
{
	if(t[u].l==t[u].r)
		return t[u].maxx;
	pushdown(u);
	int mid=(t[u].l+t[u].r)>>1;
	if(k<=mid)
		return query(lt(u),k);
	else if(mid<k)
		return query(rt(u),k);
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int i,n,q,l,len,r;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	scanf("%d",&q);
	ull ans;
	while(q--)
	{
		scanf("%d%d",&l,&r);
		ans=0;
		build(1,1,n);
		for(len=l;len<=r;len++)
		{
			for(i=len;i<=n;i++)
			{
				update(1,i-len+1,i,s[i]-s[i-len]);
			}
		}
		for(i=1;i<=n;i++)
		{
			ans^=(1llu*i*query(1,i));
		}
		printf("%llu\n",ans);
	}
	return 0;
}
