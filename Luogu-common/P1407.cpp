#include <bits/stdc++.h>
using namespace std;
struct ed {
    long long v, id;
};
vector<ed> e[1000005];
long long dfn[10005], low[100005], scc[100005], siz[100005], tot, cnt;
stack<long long> s;
void tarjan(long long u) {
    dfn[u] = ++tot;
    low[u] = tot;
    s.push(u);
    for (auto t : e[u]) {
        if (!dfn[t.v]) {
            tarjan(t.v);
            low[u] = min(low[u], low[t.v]);
        } else if (!scc[t.v]) {
            low[u] = min(low[u], dfn[t.v]);
        }
    }
    if (dfn[u] == low[u]) {
        cnt++;
        while (!s.empty()) {
            long long t = s.top();
            s.pop();
            scc[t] = cnt;
            siz[cnt]++;
            if (t == u) {
                break;
            }
        }
    }
}
long long n, m, nm;
map<string, long long> name;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        name[s1] = ++nm;
        name[s2] = ++nm;
        e[name[s1]].push_back({name[s2], i});
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        e[name[s2]].push_back({name[s1], -1});
    }
    for (int i = 1; i <= 2*n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= 2 * n; i += 2) {
        if (scc[i] == scc[i + 1]) {
            cout << "Unsafe" << endl;
        } else {
            cout << "Safe" << endl;
        }
    }
}