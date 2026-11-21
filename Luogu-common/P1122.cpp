#include<bits/stdc++.h>
using namespace std;
int n,f[100005],be[100005];vector<int> ed[100005];
void dfs(int u,int fa){
	f[u]=be[u];
	for(int v:ed[u]){
		
		if(v!=fa){dfs(v,u);
			if(f[v]>0){
				f[u]+=f[v];
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>be[i];
	}
	for(int i=1;i<n;i++){
		int a=0,b=0;
		cin>>a>>b;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	dfs(1,1);int sum=-1e9;
	for(int i=1;i<=n;i++){
		sum=max(sum,f[i]);
	}
	cout<<sum;
}
