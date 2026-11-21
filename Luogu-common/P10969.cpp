#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, dfn[200005], low[200005], scc[200005], tot, cnt;
vector<int> e[200005];
stack<int> s;
void tj(int u) {
    dfn[u] = low[u] = ++tot;
    s.push(u);
    for (int v : e[u]) {
        if (!dfn[v]) {
            tj(v);
            low[u] = min(low[u], low[v]);
        } else if (!scc[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++cnt;
        while (true) {
            int h = s.top();
            s.pop();
            scc[h] = cnt;
            if (h == u){
                break;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int a, b, c;
    string op;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> c >> op;
        if (op == "AND") {
            if (c) {
                e[a].push_back(a + n);
                e[b].push_back(b + n);
            } else {
                e[a + n].push_back(b);
                e[b + n].push_back(a);
            }
        } else if (op == "OR") {
            if (c) {
                e[a].push_back(b + n);
                e[b].push_back(a + n);
            } else {
                e[a + n].push_back(a);
                e[b + n].push_back(b);
            }
        } else if (op == "XOR") {
            if (c) {
                e[a].push_back(b + n);
                e[b].push_back(a + n);
                e[a + n].push_back(b);
                e[b + n].push_back(a);
            } else {
                e[a].push_back(b);
                e[b].push_back(a);
                e[a + n].push_back(b + n);
                e[b + n].push_back(a + n);
            }
        }
    }
    for (int i = 1; i <= 2 * n; ++i) {
        if (!dfn[i])
            tj(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (scc[i] == scc[i + n]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}