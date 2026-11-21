#include <bits/stdc++.h>
using namespace std;
namespace Main {
#define int long long
#define ull unsigned long long
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
const int N = 5e4 + 55, INF = 1e18, LEN = 32;
int n, q, a[N], c[N], s[N], lans[N][32], rans[N][32], f[N][32], ans[N][32][32];
struct node {
    int l, r;
} b[N];
deque<int> qq;
signed main() {
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    cin.tie(0), ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < LEN; j++) {
            f[i][j] = -INF;
            for (int k = max(i + j - n, 0ll); k <= j && i - k >= 1; k++)
                f[i][j] = max(f[i][j], s[i + j - k] - s[i - k - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < LEN; j++) {
            ans[i][j][j] = f[i][j];
            for (int k = j + 1; k < LEN; k++)
                ans[i][j][k] = max(ans[i][j][k - 1], f[i][k]);
        }
    }
    cin >> q;
    bool flag = true;
    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        b[i] = {l, r};
        if (l != r) flag = false;
    }
    for (int _ = 1; _ <= q; _++) {
        auto [l, r] = b[_];
        ull res = 0;
        if (!flag) {
        for (int i = 1; i <= n; i++)
            res ^= ans[i][l - 1][r - 1] * i;
        } else {
            for (int i = 1; i <= n - l + 1; i++)
                c[i] = s[i + l - 1] - s[i - 1];
            for (int i = 1; i <= n; i++) {
                if (!qq.empty() && qq.front() == i - l) qq.pop_front();
                if (i <= n - l + 1) {
                    while (!qq.empty() && c[qq.back()] < c[i]) qq.pop_back();
                    qq.push_back(i);
                }
                res ^= qq.front() * i;
            }
        }
        cout << res << endl;
    }
    return 0;
}
}
signed main() {
    Main::main();
    return 0;
}
