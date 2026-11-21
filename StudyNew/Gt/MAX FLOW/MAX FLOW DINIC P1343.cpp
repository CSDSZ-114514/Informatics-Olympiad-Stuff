#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,d[205];
ll x,flow;
struct node{
	int u,v;
	ll w;
};
vector<node> e;
vector<int> h[205];
bool bfs()
{
	memset(d,0,sizeof(d));
	d[1]=1;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u==n) return true;
		for(int i:h[u]){
			int v=e[i].v;
			if(d[v]==0&&e[i].w>0){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return false;
}
ll dfs(int u,ll mf)
{
	if(u==n) return mf;
	ll sum=0;
	for(int i:h[u]){
		int v=e[i].v;
		if(d[v]==d[u]+1&&e[i].w){
			ll f=dfs(v,min(mf,e[i].w));
			e[i].w-=f;
			e[i^1].w+=f;
			mf-=f;
			sum+=f;
			if(mf==0){
				break;
			}
		}
	}
	return sum;
}
int main()
{
	cin>>n>>m>>x;
	int a,b;ll c;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		e.push_back({a,b,c});
		h[a].push_back(e.size()-1);
		e.push_back({b,a,0});
		h[b].push_back(e.size()-1);
	}
	while(bfs()){
		flow+=dfs(1,1e9);
	}
	if(flow==0) cout<<"Orz Ni Jinan Saint Cow!";
	else cout<<flow<<' '<<(x-1)/flow+1;
	return 0;
}