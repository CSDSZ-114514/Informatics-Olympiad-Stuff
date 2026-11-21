#include<bits/stdc++.h>
using namespace std;

#define MAXN 8010

int T;
int n,m;
int fa[MAXN],dep[MAXN],siz[MAXN],h[MAXN],sons[MAXN];
int f[MAXN],g[MAXN],mex[MAXN];
int hd[MAXN],cnt;

struct Edge
{
	int u;
	int v;
	int nxt;
}edge[MAXN<<1];

void add_edge(int u,int v)
{
	edge[++cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].nxt=hd[u];
	hd[u]=cnt;
}

void dfs(int x)
{
	if(x!=1)dep[x]=dep[fa[x]]+1;
	siz[x]=1;
	h[x]=0;
	for(int i=hd[x];i;i=edge[i].nxt)
	{
		dfs(edge[i].v);
		siz[x]+=siz[edge[i].v];
		h[x]=max(h[x],h[edge[i].v]);
	}
	h[x]++;
}

void dfs_fd(int x)
{
	f[x]=g[x]=0;
	int idx=0;
	for(int i=hd[x];i;i=edge[i].nxt)
	{
		int v=edge[i].v;
		dfs_fd(v);
		if(g[v]>g[idx])idx=v;
	}
	g[x]=g[idx]+siz[x];
	sons[x]=idx;
}

void cal(int x)
{
	f[x]=0;
	for(int i=hd[x];i;i=edge[i].nxt)
	{
		int v=edge[i].v;
		cal(v);
		if(v!=sons[x])
		{
			if(siz[v]*(dep[x]+1)>=f[v])
			{
				mex[x]+=siz[v];
			}
			else
			{
				f[x]+=f[v];
			}
		}
		else
		{
			mex[x]+=siz[v];
			f[x]+=g[v];
		}
	}
	
	f[x]+=mex[x]+1;
}
void init()
{
	cnt=0;
	for(int i=1;i<=n;++i)hd[i]=f[i]=g[i]=siz[i]=dep[i]=mex[i]=0;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		
		fa[1]=1;
		init();
		for(int i=2;i<=n;++i){scanf("%d",&fa[i]);add_edge(fa[i],i);}
		
		dfs(1);
		dfs_fd(1);
		cal(1);
		
		printf("%d\n",f[1]);
	}
	return 0;
}

