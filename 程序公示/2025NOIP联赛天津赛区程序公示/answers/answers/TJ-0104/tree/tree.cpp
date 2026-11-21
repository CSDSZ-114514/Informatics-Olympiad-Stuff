#include <bits/stdc++.h>
using namespace std;
namespace Main {
#define int long long
#define endl '\n'
#define pb push_back
#define ctz __builtin_ctzll
#define clz __builtin_clzll
#ifdef LOCAL
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << ' ' << H;
    debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif // LOCAL
const int N = 1e5 + 55, INF = 1e18;
int T, n, m, a[N], sum, ans, dep[N];
vector<int> g[N];
void dfs(int x, int y) {
    if (!x) return ans = max(ans, sum), void();
    a[x] = 0;
    for (auto u : g[x]) a[x] |= a[u];
    if (a[x] & (1 << y)) return;
    a[x] |= 1 << y;
    if (clz(a[x]) + y != 63) return;
    int t = sum;
    sum += ctz(~a[x]);
    for (int i = 0; i < n - dep[x - 1]; i++) dfs(x - 1, i);
    sum = t;
}
signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin.tie(0), ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 2, x; i <= n; i++)
            cin >> x, g[x].pb(i), dep[i] = dep[x] + 1;
        ans = 0;
        for (int i = 0; i < n - dep[n]; i++) dfs(n, i);
        cout << ans << endl;
        for (int i = 1; i <= n; i++) g[i].clear();
    }
    return 0;
}
}
signed main() {
    Main::main();
    return 0;
}

