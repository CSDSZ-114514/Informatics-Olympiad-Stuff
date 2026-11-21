#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,dfn[N],low[N],tot,cnt,scc[N],siz[N],a[N],b[N],s,p;
long long na[N],rd[N],nb[N],np,ns,f[N];
vector<long long> e[N],ne[N];
stack<long long> ss;
void tarjan(int u) {
	dfn[u]=low[u]=++tot; 
	ss.push(u); 
	for(long long v:e[u]) { 
		if(!dfn[v]){
			tarjan(v); 
			low[u]=min(low[u],low[v]);
		}else if(!scc[v]){
			low[u]=min(low[u],dfn[v]);  
		} 
	}
	if(dfn[u]==low[u]){ 
		++cnt; 
		while(true){
			long long h=ss.top();
			ss.pop();
			scc[h]=cnt; 
			siz[cnt]++;
			if(h==u){ 
				break;
			}
		}
	}
}
void topo(){
	queue<long long> q;
	for(int i=1;i<=cnt;i++)if(!rd[i])q.push(i);
	for(int i=1;i<=cnt;i++)f[i]=-1e18;
	f[ns]=na[ns];
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		for(auto v:ne[u]){
			if(f[u]!=-1e18){
				f[v]=max(f[v],f[u]+na[v]);
			}
			rd[v]--;
			if(!rd[v])q.push(v);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		long long u,v;cin>>u>>v;
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>s>>p;
	for(int i=1;i<=p;i++)cin>>b[i];
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	ns=scc[s];
	for(int u=1;u<=n;u++) {
		na[scc[u]]+=a[u]; 
		for(long long v:e[u]) { 
			if(scc[u]!=scc[v]) {
				ne[scc[u]].push_back(scc[v]);
				//cout<<scc[u]<<" "<<scc[v]<<endl;
				rd[scc[v]]++;
			}
		}
	}
	for(int i=1;i<=p;i++){ 
    	nb[++np]=scc[b[i]];
	}
	//for(int i=1;i<=n;i++)cout<<scc[i]<<" ";
	topo();
	long long ans=-1e18;
	for(int i=1;i<=np;i++){
		ans=max(ans,f[nb[i]]);
	}
	cout<<ans;
	return 0;
}
