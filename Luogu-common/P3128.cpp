#include<bits/stdc++.h>
using namespace std;
int n,k;vector<int> ed[100005];
int dep[100005],fa[100005][25],d[100005];
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
void dfs1(int u,int father){
	for(int t:ed[u]){
		if(t!=father){
			dfs1(t,u);
			d[u]+=d[t];
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int a=0,b=0;
		cin>>a>>b;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	dfs(1,1);
	for(int i=1;i<=k;i++){
		int a,b;
		cin>>a>>b;
		int lcab=jumping(a,b);
		d[a]++;d[b]++;d[lcab]--;d[fa[lcab][0]]--;
	}int sum=-1e9;
	dfs1(1,1);
	for(int i=1;i<=n;i++){
		sum=max(sum,d[i]);
	}
	cout<<sum;
}
