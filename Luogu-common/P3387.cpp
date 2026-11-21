#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],suohou[10005];
vector<int> ed[10005];
vector<int> ed1[10005];



int dfn[10005],low[10005],scc[10005],csc[10005],nw[10005],tot,cnt;
stack<int> s;
void tarjan(int u){
	dfn[u]=++tot;
	low[u]=tot;
	s.push(u);
	for(int v:ed[u]){
		if(dfn[v]==0){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(scc[v]==0){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		cnt++;
		while(true){
			int q=s.top();
			s.pop();
			scc[q]=cnt;
			nw[cnt]+=a[q];
			csc[cnt]++;
			if(q==u){
				break;
			}
		}
	}
}

queue<int> k;
int rd[10005],f[10005];
void tp(){
	for(int i=1;i<=cnt;i++){
		if(rd[i]==0){
			k.push(i);
			f[i]=nw[i];
		}
	}
	while(!k.empty()){
		int u=k.front();
		k.pop();
		
		for(int t:ed1[u]){
			rd[t]--;
			f[t]=max(f[u]+nw[t],f[t]);
			if(rd[t]==0){
				k.push(t);
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int c,d;
		cin>>c>>d;
		ed[c].push_back(d);
	}
	for(int i=1;i<=n;i++){
		if(dfn[i]==0){
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int v:ed[i]){
			if(scc[i]!=scc[v]){
				ed1[scc[i]].push_back(scc[v]);
				rd[scc[v]]++;
			}
		}
	}
	tp();
	int maxsum=0;
	for(int i=1;i<=cnt;i++){
		maxsum=max(maxsum,f[i]);
	}
	cout<<maxsum;
	return 0;
}
