#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long si[1000005], pi[1000005],sums;
long long fldf[1005][1005];
void fld() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                fldf[i][j] = min(fldf[i][k] + fldf[k][j], fldf[i][j]);
            }
        }
    }
}



struct ED {
    long long u, v, w;
};
vector<ED> e;
vector<long long> h[1005];
long long mf[1005],pre[1005];
long long s = 0, t = 2 * n + 1;
bool bfs() {
    memset(mf, 0, sizeof(mf));
    queue<long long> q;
    mf[s]= 1e18;
	q.push(s); 
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        if(u==t)
            return true;
        for(auto i:h[u]){
            int v = e[i].v; 
            if(mf[v]==0 && e[i].w != 0){
                mf[v] = min(mf[u], e[i].w); 
				pre[v] = i; 
				q.push(v); 
            }
        }
    }
    return false;
}
void add(long long u,long long v,long long w){
    e.push_back({u, v, w});
    h[u].push_back(e.size() - 1);
    e.push_back({v, u, 0});
    h[v].push_back(e.size() - 1);
}
bool check(long long mint) {
    e.clear();
    for (int i=0; i<=2*n+1; ++i) h[i].clear();
    long long flow = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1 ; j <= n; j++) {
            if (fldf[i][j] <= mint) {
                add(i, j+ n, (long long)1e18);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        add(s, i, si[i]);
    }
    for (int i = 1; i <= n; i++) {
        add(i + n, t, pi[i]);
    }
    while (bfs()) {
        long long v = t;
        while (v != s) {
            long long i = pre[v];
            e[i].w -= mf[t];
			e[i^1].w += mf[t]; 
			v = e[i].u;
        }
        flow += mf[t];
    }
    if(flow==sums){
        return true;
    }else{
        return false;
    }
}
int main() {
    cin >> n >> m;
    t = 2 * n + 1;
    for (int i = 1; i <= n; i++) {
        cin >> si[i] >> pi[i];
        sums += si[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fldf[i][j] = 1e18;
        }
    }
    for (int i = 1; i <= n; i++) {
            fldf[i][i] = 0;
    }
    //cout << 555;
    for (int i = 1; i <= m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        fldf[u][v] = min(w,fldf[u][v]);
        fldf[v][u] = min(w,fldf[v][u]);
    }
    fld();
    long long l = 0, r = 1e16 + 5;
    while (l < r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid ;
        } else {
            l = mid+ 1;
        }
    }
    if(!check(l)){
        cout << -1;
    }else{
        cout << l;
    }
    return 0;
}