#include <bits/stdc++.h>
using namespace std;
long long n,f[1005][1005];
struct ED {
    long long u, v, w, c;
};
vector<ED> e;
vector<long long> h[100005];
long long s=0, t=2*n+1;
void add(long long u, long long v, long long w, long long c) {
    e.push_back({u, v, w, c});
    h[u].push_back(e.size() - 1);
    e.push_back({v, u, 0, -c});
    h[v].push_back(e.size() - 1);
}
long long pre[100005],mf[100005],cost,flow,d[100005];
bool vis[100005];
bool spfa() { 
    memset(vis, 0, sizeof(vis));
    memset(d, 0x3f, sizeof(d));
	memset(mf, 0, sizeof(mf));
    vis[s] = 1;
    queue<long long> q;
    q.push(s);
    d[s] = 0;
    mf[s] = 1e18;
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        vis[u] = 0;
        for(auto t:h[u]){
            long long v = e[t].v;
            if(d[v]>d[u]+e[t].c&&e[t].w>0){
                d[v] = d[u] + e[t].c;
                mf[v] = min(mf[u], e[t].w); 
				pre[v] = t; 
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return d[t] != 0x3f3f3f3f3f3f3f3f;
}
void csflow(){
    while(spfa()){
        long long v = t;
        while(v!=s){
            long long i = pre[v];
            e[i].w -= mf[t];
            e[i^1].w += mf[t];
            v = e[i].u;
        }
        flow += mf[t];
        cost += mf[t]*d[t];
    }
}
int main() {
    cin >> n;
    t=2*n+1;
    for (int i = 1; i <= n; i++) {
        add(0, i, 1, 0);
    }
    for (int i = 1; i <= n; i++) {
        add(i+n, 2*n+1, 1, 0);
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            long long p;
            cin >> p;
            f[i][j] = p;
            add(i, j + n, 1e9, p);
        }
    }
    csflow();
    e.clear();
    for (int i = 0; i <= 2 * n + 1; i++) h[i].clear();
    cout << cost << endl;
    cost = 0;
    flow = 0;
    
    for (int i = 1; i <= n; i++) {
        add(0, i, 1, 0);
    }
    for (int i = 1; i <= n; i++) {
        add(i+n, 2*n+1, 1, 0);
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            add(i, j + n, 1e9, -1*f[i][j]);
        }
    }
    csflow();
    cout << -1 * cost << endl;
}