#include<bits/stdc++.h>
using namespace std;
int n,f[10005][5];vector<int> ed[10005];
void dfs(int u,int fa){
	f[u][1]=1;
	for(int v:ed[u]){
		if(v!=fa){
			dfs(v,u);
			f[u][0]+=f[v][1];
			f[u][1]+=min(f[v][1],f[v][0]);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,k,m;
		cin>>a>>k;
		for(int i=1;i<=k;i++){
			cin>>m;
			ed[a].push_back(m);
			ed[m].push_back(a);
		}
	}
	dfs(0,0);
	cout<<min(f[0][0],f[0][1]);
	return 0;
}
