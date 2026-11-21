#include<bits/stdc++.h>
using namespace std;
long long mon[500005],cs,p,cp[500005];
long long n,m,rd[500005];
vector<int> ed[500005];
stack<int> s;
long long dfn[500005],low[500005],tot,scc[500005],siz[500005],cnt;
void tarjan(int u) {
	dfn[u] = low[u] = ++tot;
	s.push(u);
	for(int v:ed[u]) { 
		if(!dfn[v]) {
			tarjan(v); 
			low[u] = min(low[u], low[v]); 
		} else if(!scc[v]) {
			low[u] = min(low[u],dfn[v]);
		} 
	}
	if(dfn[u] == low[u]) { 
		++cnt; 
		while(true) {
			int h = s.top(); 
			s.pop();
			scc[h] = cnt; 
			siz[cnt]++; 
			if(h == u) { 
				break;
			}
		}
	}
}
vector<int> gd[500005];
long long grd[500005],gcd1[500005],gnw[500005];
long long d[500005],vis[500005];
queue<int> q;
void spfa(int st) {
	for(int i=1; i<=n; i++) {
		d[i] = -1e9;
	}
	d[scc[st]] = 0; 
	q.push(scc[st]); 
	vis[scc[st]] = 1;
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0; 
		
		for(int t:gd[u]) {  
			if(d[t] <d[u] + gnw[t]) { 
				d[t] = d[u] + gnw[t];
				if(!vis[t]) { 
					q.push(t);  
					vis[t] = 1; 
				}
			}
		}
	}
} 
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		long long a,b;
		cin>>a>>b;
		ed[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		mon[i]=a;
	}
	cin>>cs>>p;
	for(int i=1;i<=p;i++){
		long long a=0;
		cin>>a;
		cp[i]=a;
	}
	tarjan(cs);
	for(int i=1; i<=n; i++) {
		gnw[scc[i]]+= mon[i];
		for(int v:ed[i]) { 
			if(scc[i]==0)continue;
			if(scc[i] != scc[v]) {
				gd[scc[i]].push_back(scc[v]); 
			}
		}
	}
	spfa(cs);
	long long ans=0;
	for(int i=1;i<=p;i++){
		ans=max(ans,d[scc[cp[i]]]);
	}
	cout<<ans+gnw[scc[cs]];
}
