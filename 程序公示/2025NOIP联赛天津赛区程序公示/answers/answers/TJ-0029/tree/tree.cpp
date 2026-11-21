#include <bits/stdc++.h>
using namespace std;
const int N=8e3+5;
int t,n,m,edge[N][N],son[N],fa[N],cnt[N],dep[N];
int jishu[N],sum[N];
void init()
{
	memset(edge,0,sizeof(edge));
	memset(son,0,sizeof(son));
	memset(cnt,0,sizeof(cnt));
	memset(dep,0,sizeof(dep));
	memset(jishu,0,sizeof(jishu));
	memset(sum,0,sizeof(sum));
	return ;
}
void dfs(int u)
{
	if(jishu[u]==0)return ;
	for(int i=1;i<=jishu[u];i++)
	{
		dep[edge[u][i]]=dep[u]+1;
		dfs(edge[u][i]);
		son[u]+=(son[edge[u][i]]+1);
	}
	return ;
}
bool cmp(int a,int b){return sum[a]>sum[b];}
void find_ans(int u)
{
	if(jishu[u]==0){sum[u]=1;cnt[u]=0;return ;}
	for(int i=1;i<=jishu[u];i++)find_ans(edge[u][i]);
	sort(edge[u]+1,edge[u]+jishu[u]+1,cmp);
	int sum_son=0,sum_sum=0;
	cnt[u]=cnt[edge[u][1]]+1;sum[u]=sum[edge[u][1]];
	for(int i=2;i<=jishu[u];i++)sum_son+=(son[edge[u][i]]+1),sum_sum+=sum[edge[u][i]];
	if(sum_sum<sum_son*(dep[u]+1))cnt[u]+=sum_son;
	else
	{
		for(int i=2;i<=jishu[u];i++)cnt[u]=max(cnt[u],cnt[edge[u][i]]+1);
		sum[u]+=sum_sum; 
	}
	sum[u]+=(cnt[u]+1);
	return ;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		init();
		cin>>n>>m;
		for(int i=2;i<=n;i++)
		{
			cin>>fa[i];
			edge[fa[i]][++jishu[fa[i]]]=i;
		}
		dfs(1);
		find_ans(1);
		cout<<sum[1]<<endl;
	}
	return 0;
}
