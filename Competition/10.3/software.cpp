#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct SF{
	long long w,v;
}sf[1000005];
struct SFF{
	long long w,v;
}sff[1000005];
long long dfn[1000005],low[1000005],tot,
		  scc[1000005],cnt,siz[1000005],rd[1000005];
stack<long long> s;
vector<long long> e[1000005];
vector<long long> ne[1000005];
void tarjan(int u){
	dfn[u]=low[u]=++tot; 
	s.push(u);
	for(long long v:e[u]) { 
		if(!dfn[v]) {
			tarjan(v); 
			low[u] = min(low[u], low[v]);
		} else if(!scc[v]) {
			low[u] = min(low[u],dfn[v]);
		} 
	}
	if(dfn[u]==low[u]) { 
		++cnt; 
		while(true){
			long long h=s.top();
			s.pop();
			scc[h]=cnt; 
			siz[cnt]++;
			if(h==u) { 
				break;
			}
		}
	}
}
long long f[105][505];
void dfs(long long u){
	for(int i=0;i<=m;i++)f[u][i]=-1e18;
	if(u==0)f[0][0]=0;
	if(sff[u].w<=m)f[u][sff[u].w]=sff[u].v;
	for(long long v:ne[u]){
		dfs(v);
		long long mxf[505];
		for(int i=0;i<=505;i++)mxf[i]=-1e18;
		for(int i=0;i<=505;i++)mxf[i]=max(mxf[i],f[u][i]);
		for(int i=0;i<=m;i++){
			if(f[u][i]==-1e18)continue;
			for(int j=0;j+i<=m;j++){
				if(f[v][j]==-1e18)continue;
				mxf[i+j]=max(mxf[i+j],f[u][i]+f[v][j]);
			}
		}
		for(int i=0;i<=m;i++){
			f[u][i]=mxf[i];
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>sf[i].w;
	for(int i=1;i<=n;i++)cin>>sf[i].v;
	for(int i=1;i<=n;i++){
		long long d;cin>>d;
		if(d==0)continue;
		e[d].push_back(i);
	}
	for(int i=1;i<=n;i++) {
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int u=1;u<=n;u++) {
		//nw[scc[u]]+=w[u]; 
		sff[scc[u]].v+=sf[u].v;
		sff[scc[u]].w+=sf[u].w;
		for(int v:e[u]) {
			if(scc[u]!=scc[v]) {
				ne[scc[u]].push_back(scc[v]); 
				rd[scc[v]]++;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(rd[i]==0){
			ne[0].push_back(i);
		}
	}
	dfs(0);
	long long ans=-1e18;
	for(int i=0;i<=m;i++)ans=max(ans,f[0][i]);
	cout<<ans;
	return 0;
}
