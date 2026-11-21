#include <bits/stdc++.h>
using namespace std;
long long n, m, mm, bb[10005];
struct EDGE {
    long long v, w, b, id;
};

struct NODE {
    long long u, dis;
    bool operator<(const NODE p) const { return dis > p.dis; }
};
priority_queue<NODE> q;
long long d[100005];
bool vis[100005];
vector<EDGE> e[100005];
void djgun(long long s) {
    for (int i = 1; i <= n; i++) {
        d[i] = 1e18;
        vis[i] = 0;
    }
    d[s] = 0;
    q.push({s, 0});
    while (!q.empty()) {
        NODE u = q.top();
        q.pop();
        if (vis[u.u]) {
            continue;
        }
        vis[u.u] = true; 
        for (auto t : e[u.u]) {
            if (vis[t.v]) continue;
            long long cost = t.w;
            if (t.id == mm) {
                cost = 0;
            }
            if (t.id != mm && t.b > bb[mm]) continue;
            if (d[t.v] > d[u.u] + cost) {
                d[t.v] = d[u.u] + cost;
                q.push({t.v, d[t.v]});
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        long long u, v, w;
        cin >> u >> v >> w >> bb[i];
        e[u].push_back({v, w, bb[i], i});
        e[v].push_back({u, w, bb[i], i});
    }
    long long dis = 1e18 + 1;
    for (int i = 1; i <= m; i++) {
        mm = i;
        djgun(1);
        dis = min(dis, d[n]);
    }
    if (dis == 1e18 + 1) cout << -1 << "\n";
    else cout << dis << "\n";
}