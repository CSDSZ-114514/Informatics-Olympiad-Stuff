#include <bits/stdc++.h>
using namespace std;
long long nn, a[100005], p, m, f, n, ss;
struct ED {
    long long u, v, w, c;
};
vector<ED> e;
vector<long long> h[100005];
long long s, t;
void add(long long u, long long v, long long w, long long c) {
    e.push_back({u, v, w, c});
    h[u].push_back(e.size() - 1);
    e.push_back({v, u, 0, -c});
    h[v].push_back(e.size() - 1);
}
long long pre[100005], mf[100005],cost,flow,d[100005];
bool vis[100005];
bool spfa(){
    memset(vis,0,sizeof(vis));
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
        for(auto i:h[u]){
            if(d[e[i].v]>d[e[i].u]+e[i].c&&e[i].w){
                if(!vis[e[i].v]){
                    vis[e[i].v] = 1;
                    q.push(e[i].v);
                }
                d[e[i].v] = d[e[i].u] + e[i].c;
                mf[e[i].v] = min(mf[u], e[i].w);
                pre[e[i].v] = i; 
            }
        }
    }
    return d[t] != 0x3f3f3f3f3f3f3f3f;
}
void cosflow(){
    while(spfa()){
        long long v = t;
        while(v!=s){
            long long i = pre[v];
            e[i].w -= mf[t];
            e[i ^ 1].w += mf[t];
            v = e[i].u;
        }
        cost += d[t] * mf[t];
        flow += mf[t];
    }
}
int main() {
    cin >> nn;
    t = 2 * nn + 1;
    for (int i = 1; i <= nn; i++) {
        cin >> a[i];
    }
    cin >> p >> m >> f >> n >> ss;
    for (int i = 1; i <= nn; i++) {
        add(s, i + nn, a[i], 0);
        add(i, t, a[i], 0);
        add(s, i, 1e18, p);
        if (i + 1 <= nn) add(i + nn, i + 1 + nn, 1e18, 0);
        if (i + m <= nn) add(i + nn, i + m, 1e18, f);
        if (i + n <= nn) add(i + nn, i + n, 1e18, ss);
    }
    cosflow();
    cout << cost;
    return 0;
}