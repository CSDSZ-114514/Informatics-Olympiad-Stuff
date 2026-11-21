#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int c,t,n,m,rans;
struct info
{
	int ori;
	int xjb1;
	int xjb2;
	int w;
	int no;
}seq[305];
int ksm(int di,int mi)
{
	long long ans=1;
	while(mi)
	{
		if(mi&1)
		{
			ans*=di;
			ans%=mod;
		}
		di*=di;
		di%=mod;
		mi>>=1;	
	}	
	return ans;
}
bool way(info a,info b)
{
	if(a.xjb1!=b.xjb1) return a.xjb1>b.xjb1;
	else if(a.xjb2!=b.xjb2) return a.xjb1>b.xjb1;
	else if(a.ori!=b.ori) return a.ori>b.ori;
	else return a.no<b.no;
}
void check()
{
	sort(seq+1,seq+n+1,way);
	for(int i=1;i<=n;i++)
	{
		if(m>2)
		{
			m-=seq[i].w;
			continue;
		}
		else if(m<2) return;
		else
		{
			if(seq[i].w==1&&seq[i+1].w==2)
			{
				int ha=0;
				for(int j=i+2;i<=n;i++)
				{
					if(seq[j].w==1)
					{
						ha=seq[j].ori;
						break;
					}
				}
				if(seq[i].ori+ha<seq[i+1].ori)  rans++;
			}
		}
		return;
	}
}
void dfs(int w,int p)
{
	if(w&1) seq[p].xjb1=seq[p].ori;
	else
	{
		seq[p].xjb1=seq[p].ori/2;
		if(seq[p].ori&1) seq[p].xjb2=1;
	}
	seq[p].w=w;
	if(p==n) check();
	for(int i=1;i<=2;i++) dfs(i,p+1);
	return;
}
signed main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		rans=0;
		memset(seq,0,sizeof(seq));
		for(int i=1;i<=n;i++)
		{
			cin>>seq[i].ori;
			seq[i].no=i;
		}
		for(int i=1;i<=2;i++) dfs(i,1);
		cout<<ksm(2,n)-rans;
	}
	return 0;
}
