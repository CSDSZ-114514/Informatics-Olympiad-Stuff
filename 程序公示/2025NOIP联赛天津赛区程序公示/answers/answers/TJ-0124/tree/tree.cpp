#include<bits/stdc++.h>
using namespace std;
int T;
int ans,n,m;
int p[8005];
int v[8005];
int s[25][25];
int len[25];
bool vis[25];
vector<int> G[8005];
void solve(int x,int y)
{
	if(G[x].size()==0)
	{
		s[y][++len[y]]=v[x];
		return;
	}
	for(int i=0;i<G[x].size();i++)
	{
		solve(G[x][i],y);
		s[y][++len[y]]=v[G[x][i]];
	}
	s[y][++len[y]]=v[x];
}
void dfs(int x)
{
	if(x==n+1)
	{
		for(int i=1;i<=n;i++) solve(i,i);
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=len[i];j++) vis[s[i][j]]=true;
			for(int j=0;j<n;j++)
			{
				if(!vis[j])
				{
					sum+=j;
					break;
				}
			}
			for(int j=0;j<n;j++) vis[j]=false;
			len[i]=0;
		}
		ans=max(sum,ans);
		/*if(ans==8)
		{
			for(int i=1;i<=n;i++) cout<<v[i]<<" ";
			cout<<endl;
		}*/
		return;
	}
	for(int i=0;i<n;i++)
	{
		v[x]=i;
		dfs(x+1);
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>m;
		for(int i=2;i<=n;i++)
		{
			cin>>p[i];
			G[p[i]].push_back(i);
		}
		dfs(1);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) G[i].clear();
	}
	return 0;
}
