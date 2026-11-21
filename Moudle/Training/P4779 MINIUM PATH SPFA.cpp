#include <bits/stdc++.h>
using namespace std;
long long n, m, s;
struct ED {
    long long v, w;
};
vector<ED> e[100005];
long long d[100005];
bool vis[100005];
void spfa(long long s) {
    memset(d, 0x3f, sizeof(d));
    queue<long long> q;
    q.push(s);
    d[s] = 0;
    vis[s] = 1;
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
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    spfa(s);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    return 0;
}