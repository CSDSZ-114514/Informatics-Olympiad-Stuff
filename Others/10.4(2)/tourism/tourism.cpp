#include<bits/stdc++.h>
using namespace std;
long long n,k,q;
long long dep[1000005],fa[1000005][40],cfn[1000005],dst[1000005];
vector<long long> e[1000005];
void dfs(int u, int father) {
    dep[u] = dep[father] + 1;
	fa[u][0] = father;
	
	for(int i=1; i<=20; i++) {
		fa[u][i] = fa[fa[u][i-1]][i-1]; //倍增法求fa[u][i] 
	}
	
	for(int v:e[u]) {
		if(v != father) {
			dfs(v, u);
		}
	}
}
int lca(int u, int v) {
	//保证dep[u]>=dep[v] 
	if(dep[u] < dep[v]) {
		swap(u, v);
	}
	
	//统一深度, 层数由高到低判断，只要保证跳后 dep[u] >=dep[v]，则跳 
	for(int i=20; i>=0; i--) {
		if(dep[fa[u][i]] >= dep[v]) {
			u = fa[u][i];
		}
	}
	
	if(u==v) {
		return u;
	}
	
	//找最近祖先结点的下一层节点，层数由高到低判断，只要跳后 u!=v，则跳 
	for(int i=20; i>=0; i--) {
		if(fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	} 
	
	return fa[u][0]; //u向上跳一步就是最近公共祖先 
}
queue<long long> Q;
void bfs() {
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
        //cout<<u;
		for(long long v:e[u]) {
			if (dst[v] == 1e9) {
				dst[v] = dst[u] + 1;
				Q.push(v);
			}
		}
	}
}
int main(){
    cin>>n>>k>>q;
    for(int i=1;i<=n-1;i++){
        long long a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1,0);
    for(int i=1;i<=k;i++){
        long long g;
        cin>>g;
        Q.push(g);dst[g] = 0;
    }
    for(int i=1;i<=n;i++){
        dst[i]=1e9;
    }
    bfs();
    //for(int i=1;i<=n;i++)cout<<dst[i]<<endl;
    for(int i=1;i<=q;i++){
        int u, v; cin >> u >> v;
        //cout<<dst[u] + dst[v]<<" "<<dep[u]+dep[v]-2*dep[lca(u,v)];
        cout<<min(dst[u] + dst[v],dep[u]+dep[v]-2*dep[lca(u,v)]) << "\n";
    }
}