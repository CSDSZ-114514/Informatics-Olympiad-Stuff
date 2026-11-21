#include <bits/stdc++.h>
using namespace std;
namespace Main {
#define int long long
#define endl '\n'
#define pb push_back
#ifdef LOCAL
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << ' ' << H;
    debug_out(T...);
}
#define debug(...) cerr << "[" << __VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif // LOCAL
const int N = 1e5 + 55, INF = 1e18;
int n, m, a[N], b[N];
signed main() {
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    cin.tie(0), ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int mi = INF;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i], mi = min(mi, a[i] + b[i]);
    sort(a + 1, a + n + 1);
    int ans = 0, s = 0;
    for (int i = 0; i <= n; i++) {
        if (i) s += a[i];
        if (s <= m) ans = max(ans, i + (m - s) / mi * 2);
    }
    cout << ans << endl;
    return 0;
}
}
signed main() {
    Main::main();
    return 0;
}
