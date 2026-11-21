#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
long t,n,m;
long f[10040];
long f2[10040];
long f3[10040];
long fa[10040];
long dep[10040];
long sonnum[10040];
vector<long> son[10040];
long solve(long rt)
{
	if(sonnum[rt] == 1)
	{
		f3[rt] = 1;
		return 1;
	}/*
	for(long i = 0;i < son[rt].size();i++)
		if(sonnum[son[rt][i]] > nowmax)
		{
			nowmax = sonnum[son[rt][i]];
			nowson = son[rt][i];
		}*/
	long nowmax = -(1e9+10);
	long nowson = 0;
	for(long i = 0;i < son[rt].size();i++)
		f2[son[rt][i]] = solve(son[rt][i]);
	for(long i = 0;i < son[rt].size();i++)
		if(f[son[rt][i]]+sonnum[son[rt][i]]*dep[rt]-f2[son[rt][i]] > nowmax)
		{
			nowson = son[rt][i];
			nowmax = f[son[rt][i]]+sonnum[son[rt][i]]*dep[rt]-f2[son[rt][i]];
			//cout<<nowmax<<" "<<nowson<<endl;
		}
	long nowans = f[nowson];
	long nowsons = sonnum[nowson];
	if(nowmax < 0)
	{
		nowsons = 0;
		for(long i = 0;i < son[rt].size();i++)
			nowsons = max(nowsons,f3[son[rt][i]]);
		nowans = 0;
		for(long i = 0;i < son[rt].size();i++)
		{
			long nowf = f2[son[rt][i]];
			if(sonnum[son[rt][i]]*dep[rt] > nowf)
				nowsons+=sonnum[son[rt][i]];
			else
				nowans+=nowf;
		}
	}
	else
	{
		for(long i = 0;i < son[rt].size();i++)
		{
			if(son[rt][i] == nowson)
				continue;
			//cout<<rt<<" "<<nowans<<" "<<nowsons<<endl;
			long nowf = f2[son[rt][i]];
			if(sonnum[son[rt][i]]*dep[rt] > nowf)
				nowsons+=sonnum[son[rt][i]];
			else
				nowans+=nowf;
		}
	}
	f3[rt] = nowsons+1;
	//cout<<rt<<" "<<nowans<<" "<<nowsons<<endl;
	return nowsons+nowans+1;
}
void dfs1(long now,long depth)
{
	sonnum[now] = 1;
	dep[now] = depth;
	for(long i = 0;i < son[now].size();i++)
	{
		dfs1(son[now][i],depth+1);
		sonnum[now]+=sonnum[son[now][i]];
	}
	return;
}
void dfs2(long now)
{
	if(sonnum[now] == 1)
	{
		f[now] = 1;
		return;
	}
	long nowmax = 0;
	for(long i = 0;i < son[now].size();i++)
		dfs2(son[now][i]);
	for(long i = 0;i < son[now].size();i++)
		if(f[son[now][i]] > nowmax)
			nowmax = f[son[now][i]];
	f[now] = sonnum[now]+nowmax;
	return;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(long i = 1;i <= n;i++)
			f[i] = 0;
		for(long i = 1;i <= n;i++)
			son[i].clear();
		for(long i = 2;i <= n;i++)
		{
			cin>>fa[i];
			son[fa[i]].push_back(i);
		}/*
		if(m <= 2)
		{
			cout<<n+1<<endl;
			continue;
		}*/
		dfs1(1,1);
		dfs2(1);
		cout<<solve(1)<<endl;
	}
	return 0;
}
//long long
