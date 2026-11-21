#include <bits/stdc++.h>
using namespace std;
long long n, m, s, t;
struct ED {
    long long u, v, w;
};
vector<ED> e;
vector<long long> h[100005];
void add(long long u, long long v, long long w) {
    e.push_back({u, v, w});
    h[u].push_back(e.size() - 1);
    e.push_back({v, u, 0});
    h[v].push_back(e.size() - 1);
}
long long mf[100005],pre[100005];
bool bfs(){
    memset(mf, 0, sizeof(mf));
    queue<long long> q;
    q.push(s);
    mf[s] = 1e18;
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        if(u==t){
            return true;
        }
        for(auto t:h[u]){
            long long v = e[t].v;
            if(e[t].w&&!mf[v]){
                mf[v] = min(mf[u], e[t].w);
                q.push(v);
                pre[v] = t;
            }
        }
    }
    return false;
}
long long flow;
void ek(){
    while(bfs()){
        long long p = t;
        while(p!=s){
            e[pre[p]].w -= mf[t];
            e[pre[p]^1].w += mf[t];
            p = e[pre[p]].u;
        }
        flow += mf[t];
    }
    return;
}
int main() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    ek();
    cout << flow;
    return 0;
}