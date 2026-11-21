#include<bits/stdc++.h>
using namespace std;
int n,Q;vector<int> ed[100005];
int dep[100005],fa[100005][25];
void dfs(int u,int father){
	dep[u]=dep[father]+1;
	fa[u][0]=father;
	for(int i=1;i<=20;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int t:ed[u]){
		if(t!=father){
			dfs(t,u);
		}
	}
}
int jumping(int u,int v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	for(int i=20;i>=0;i--){
		if(dep[fa[u][i]]>=dep[v]){
			u=fa[u][i];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=20;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
	
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int a=0,b=0;
		cin>>a>>b;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	dfs(1,1);
	cin>>Q;
	for(int i=1;i<=Q;i++){
		int a=0,b=0;
		cin>>a>>b;
		cout<<dep[a]-dep[jumping(a,b)]+dep[b]-dep[jumping(a,b)]<<'\n';
	}
}
