#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ed[100005];int dfn[100005],low[100005],tot,root,ged[100005],ges;
void TJ(int u){
	dfn[u]=low[u]=++tot;
	int child=0;
	for(int v:ed[u]){
		if(dfn[v]==0){
			TJ(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				child++;
				if(u!=root||child>=2){
					ged[u]=1;
				}
			}
		}else{
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a=0,b=0;
		cin>>a>>b;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(dfn[i]==0){
			root=i;
			TJ(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(ged[i]){
			ges++;
		}
	}
	cout<<ges<<endl;
	for(int i=1;i<=n;i++){
		if(ged[i]){
			cout<<i<<" ";
		}
	}
	return 0;
}
