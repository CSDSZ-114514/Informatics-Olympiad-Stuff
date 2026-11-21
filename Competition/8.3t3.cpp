#include <bits/stdc++.h>
using namespace std;
int n, q, r, cd[1000005];
vector<long long> e[1000005];
int st[1000005], mst[1000005], ans[1000005], f[1000005];
void dfs(int u, int fa) {
    st[u] = 1;
    for (auto v : e[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        st[u] += st[v];
        mst[u] = max(mst[u], st[v]);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> r;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(r, r);
    for (int i = 0; i < n; i++) {
        f[i] = n - st[i] + mst[i];
        // cout << f[i];
    }
    for (int i = 0; i <= n + 5; i++) {
        ans[i] = n;
    }
    for (int i = 0; i < n; i++) {
        ans[f[i]] = min(ans[f[i]], i);
    }
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = min(ans[i], ans[i + 1]);
    }
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
    return 0;
}