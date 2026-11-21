#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long N=1e5+5;
long long d[N];
long long dep[N],fa[N][40],cfn[N],qzh[N];
vector<long long> e[N];
void dfs(int u, int father) {
    qzh[u]=qzh[father]+d[u];
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for(int i=1; i<=20; i++) {
		fa[u][i] = fa[fa[u][i-1]][i-1]; 
	}
	for(int v:e[u]) {
		if(v != father) {
			dfs(v, u);
		}
	}
}
int lca(int u, int v) {
	if(dep[u] < dep[v]) {
		swap(u, v);
	}
	for(int i=20; i>=0; i--) {
		if(dep[fa[u][i]] >= dep[v]) {
			u = fa[u][i];
		}
	}
	if(u==v) {
		return u;
	}
	for(int i=20; i>=0; i--) {
		if(fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	} 
	return fa[u][0];  
}
int  main(){
    freopen("machine.in","r",stdin);
    freopen("machine.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<n;i++){
        long long a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
        d[a]++;d[b]++;
    }
    //qzh[1]=d[1];
    dfs(1,0);
    // for(int i=1;i<=n;i++){
    //     cout<<qzh[i]<<" ";
    // }
    //cout<<qzh[4];
    for(int i=1;i<=m;i++){
        long long a,b;
        cin>>a>>b;
        cout<<qzh[a]-qzh[lca(a,b)]+qzh[b]-qzh[lca(a,b)]+d[lca(a,b)]<<endl;
    }
}
