#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=8e3+10;
int n,m;
int T,fa[N],a[N],sum,ans;
vector<int> G[N],E[N];
void DFS(int u){
	E[u].clear();
	E[u].push_back(a[u]);
	for(auto v:G[u]){
		DFS(v);
		for(auto i:E[v]) E[u].push_back(i);
	}
	for(int i=0;i<=n+1;i++){
		bool flag=0;
		for(auto j:E[u]) 
			if(j==i){
				flag=1;
				break;
			} 
		if(!flag){
			sum+=i;
			break;
		} 
	}
}
void dfs(int d){
	if(d==n+1){
		sum=0;
		DFS(1);
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<=n;i++){
		a[d]=i;
		dfs(d+1);
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;ans=0;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=2;i<=n;i++){
			cin>>fa[i];
			G[fa[i]].push_back(i);
		} 
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}
