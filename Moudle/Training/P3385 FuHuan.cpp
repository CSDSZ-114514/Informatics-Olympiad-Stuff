#include <bits/stdc++.h>
using namespace std;
long long n, m;
struct ED {
    long long v, w;
};
vector<ED> e[100005];
long long d[100005];
bool vis[100005];
long long cnt[100005];
bool spfa(long long s) {
    queue<long long> q;
    q.push(s);
    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    vis[s] = 1;
    d[s] = 0;
    while (!q.empty()) {
        long long u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto t : e[u]) {
            if (d[t.v] > d[u] + t.w) {
                d[t.v] = d[u] + t.w;
                if (!vis[t.v]) {
                    q.push(t.v);
                    vis[t.v] = 1;
                }
                cnt[t.v] = cnt[u] + 1;
                if (cnt[t.v] > n) {
                    return false;
                }
            }
        }
    }
    return true;
}
int main() {
    long long T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            e[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            long long u, v, w;
            cin >> u >> v >> w;
            if (w >= 0) {
                e[u].push_back({v, w});
                e[v].push_back({u, w});
            } else {
                e[u].push_back({v, w});
            }
        }
        if(spfa(1)){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}