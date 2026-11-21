#include<bits/stdc++.h>
using namespace std;
//每个点往四个方向建图，然后跑强连通分量
//计算入度为0的点的个数（起点），出度为0的点的个数，终点
//起点和终点建缆车，两个数取最大值 

int n, m, dfn[300005], low[300005], tot, g[505][505];
int scc[300005], cnt, in[300005],out[300005]; 
vector<int> e[300005]; 
stack<int> s;

void tarjan(int u) {
	dfn[u] = low[u] = ++tot;
	s.push(u);
	
	for(int v: e[u]) {
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u],low[v]);
		} else if(!scc[v]) {
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(dfn[u] == low[u]) {
		cnt++;
		while(1) {
			int h = s.top();
			s.pop();
			scc[h]=cnt;
			if(h==u) {
				break;
			}
		}
	}
}

void build(int i, int j) {
	int u = (i-1)*m + j;
	int v;
	if(i>1 && g[i-1][j]<=g[i][j]) {
		v = u - m;
		e[u].push_back(v);
	}
	if(j<m && g[i][j+1]<=g[i][j]) {
		v = u+1;
		e[u].push_back(v);
	}
	if(i<n && g[i+1][j]<=g[i][j]) {
		v = u+m;
		e[u].push_back(v);
	}
	if(j>1 && g[i][j-1]<=g[i][j]) {
		v = u-1;
		e[u].push_back(v);
	}
}
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
int main() {
	freopen("ski.in", "r", stdin);
	freopen("ski.out", "w", stdout);
	
	cin>>m>>n; //注意输入 
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>g[i][j];
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			build(i, j);
		}
	}
	
	for(int i=1; i<=n*m; i++) {
		if(!dfn[i]) {
			tarjan(i);
		}
	}
		
	for(int u=1; u<=n*m; u++) {
		for(int v:e[u]) {
			if(scc[u] != scc[v]) {
				out[scc[u]]++;
				in[scc[v]]++;
			}
		}
	}
	
	int ans1=0, ans2=0;
	for(int i=1; i<=cnt; i++) {
		if(in[i]==0) {
			ans1++;
		}
		if(out[i]==0) {
			ans2++;
		}
	}
	
	if(cnt == 1) { //注意特殊情况 
		cout<<0;
	} else {
		cout<<max(ans1, ans2);
	}
	
	return 0;
}

