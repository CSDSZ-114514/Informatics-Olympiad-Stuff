#include <bits/stdc++.h>
using namespace std;
long long n, m, s;
struct ED {
    long long v, w;
};
vector<ED> e[100005];
long long d[100005];
struct STT {
    long long u, dis;
    bool operator<(const STT p) const { return dis > p.dis; }
};
bool vis[100005];
priority_queue<STT> pq;
void djgun(long long s) {
    for (int i = 1; i <= n; i++) {
        d[i] = 1e18;
    }
    d[s] = 0;
    pq.push({s, 0});
    while (!pq.empty()) {
        long long u = pq.top().u;
        long long dis = pq.top().dis;
        pq.pop();
        if(vis[u])continue;
        vis[u] = true;
        for(auto t:e[u]){
            if(!vis[t.v]&&dis+t.w<d[t.v]){
                d[t.v] = dis + t.w;
                pq.push({t.v, d[t.v]});
            }
        }
    }
}
int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v,w});
    }
    djgun(s);
    for (int i = 1; i <= n;i++){
        cout << d[i] << " ";
    }
        return 0;
}