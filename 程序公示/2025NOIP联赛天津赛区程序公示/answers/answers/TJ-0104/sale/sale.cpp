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
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif // LOCAL
const int N = 1e5 + 55, M = 1e5, MOD = 998244353, INF = 1e18;
int sid, T, n, m, a[N], fac[N], ifac[N], inv[N], bs[N];
int binom(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}
signed main() {
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    cin.tie(0), ios_base::sync_with_stdio(false);
    cin >> sid >> T;
    fac[0] = ifac[0] = inv[1] = bs[0] = 1;
    for (int i = 1; i <= M; i++) {
        if (i > 1) inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
        fac[i] = fac[i - 1] * i % MOD;
        ifac[i] = ifac[i - 1] * inv[i] % MOD;
        bs[i] = bs[i - 1] * 2 % MOD;
    }
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        a[n + 1] = 0;
        sort(a + 1, a + n + 1, greater<int>());
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int i1 = 0;
            for (int j = i + 1; j <= n + 1; j++)
                if (a[j] * 2 <= a[i]) { i1 = j; break; }
            for (int j = i + 1, k = n + 1; j < i1; j++) {
                while (k - 1 > j && a[k - 1] < a[i] - a[j]) k--;
                if (a[k] >= a[i] - a[j]) continue;
                int c1 = i - 1, c2 = j - i - 1, c3 = i1 - i - 1, c4 = n - k + 1;
                ans = (ans + binom(c1 + c2, m - c1 - 2) * bs[c4]) % MOD;
            }
        }
        cout << (bs[n] + MOD - ans) % MOD << endl;
    }
    return 0;
}
}
signed main() {
    Main::main();
    return 0;
}
