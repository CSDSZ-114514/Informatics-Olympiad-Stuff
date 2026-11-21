#include<bits/stdc++.h>
using namespace std;
long long w,l,a[1005][1005],n=w*l;
long long dfn[100005],low[100005],tot=0,scc[100005],cnt,siz[100005];
long long cd[100005],rd[100005],ans1,ans2;
vector<long long> g[100005];
stack<long long> s;
vector<long long> e[100005];
long long topos(long long x,long long y){
    return (x-1)*w+y;
}
void ade(long long i,long long j){
    if(i>1){
        if(a[i][j]>=a[i-1][j])e[topos(i,j)].push_back(topos(i-1,j));
        if(a[i][j]<=a[i-1][j])e[topos(i-1,j)].push_back(topos(i,j));
    }
    if(j>1){
        if(a[i][j]>=a[i][j-1])e[topos(i,j)].push_back(topos(i,j-1));
        if(a[i][j]<=a[i][j-1])e[topos(i,j-1)].push_back(topos(i,j));
    }
}
void tarjan(int u) {
	dfn[u] = low[u] = ++tot; 
	s.push(u);
	
	for(int v:e[u]) { 
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

int main(){
    cin>>w>>l;n=w*l;
    for(int i=1;i<=l;i++)for(int j=1;j<=w;j++)cin>>a[i][j];
    for(int i=1;i<=l;i++)for(int j=1;j<=w;j++)ade(i,j);
    for(int i=1;i<=n;i++) if(!dfn[i])tarjan(i);
    for(int u=1; u<=n; u++)for(int v:e[u]) if(scc[u] != scc[v]) g[scc[u]].push_back(scc[v]),rd[scc[v]]++,cd[scc[u]]++;
    for(int i=1;i<=cnt;++i){if(!rd[i]) ++ans1;if(!cd[i]) ++ans2;}
	cout<<(cnt==1)?0:max(ans1,ans2);
}