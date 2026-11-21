#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 5010;
const int mod = 998244353;
int a[maxn] = {0}, b[maxn] = {0};
struct node {
    int val, c, id;
} c[maxn];
ll f[maxn << 1] = {0};
int n = 0, m = 0;
bool cmp(node a, node b) {
    if (1ll * a.val * b.c != 1ll * b.val * a.c) {
        return 1ll * a.val * b.c > 1ll * b.val * a.c;
    }
    else if (a.val != b.val) {
        return a.val > b.val;
    }
    else {
        return a.id < b.id;
    }
}
int ans = 0;
void dfs(int now) {
    if (now == n + 1) {
        for (int i = 1; i <= n; i ++) {
            c[i].val = a[i];
            c[i].c = b[i];
            c[i].id = i;
        }
        for (int i = 0; i <= m; i ++) {
            f[i] = 0;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = m; j >= c[i].c; j --) {
                f[j] = max(f[j], f[j - c[i].c] + c[i].val);
            }
        }
        sort(c + 1, c + 1 + n, cmp);
        int m_ = m;
        ll num = 0;
        for (int i = 1; i <= n; i ++) {
            if (m_ >= c[i].c) {
                num += c[i].val;
                m_ -= c[i].c;
            }
        }
        if (num == f[m]) {
            // for (int i = 1; i <= n; i ++) {
            //     printf("%d ", b[i]);
            // }
            // printf("\n");
            ans ++;
        }
        return;
    }
    b[now] = 1;
    dfs(now + 1);
    b[now] = 2;
    dfs(now + 1);
}
ll ksm(ll a, ll n) {
    ll res = 1;
    while(n != 0) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1ll;
    }
    return res;
}
bool cmp2(int a, int b) {
    return a > b;
}
void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    if (m == 2) {
        ll res = ksm(2, n);
        sort(a + 1, a + 1 + n, cmp2);
        ll v[3] = {0};
        for (int i = 2; i <= n; i ++) {
            if (a[i] * 2 > a[1] && a[i] < a[1]) {
                res --;
                if (res < 0) {
                    res += mod;
                }
                res %= mod;
            }
        }
        for (int i = 2; i <= n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                if (a[1] >= a[i] * 2 && a[1] >= a[j] * 2) {
                    if (a[i] + a[j] > a[1]) {
                        res -= ksm(2, n - j);
                        if (res < 0) {
                            res += mod;
                        }
                        res %= mod;
                    }
                }
                if (a[i] * 2 > a[1] && a[j] * 2 <= a[1]) {
                    if (a[i] + a[j] < a[1]) {
                        res -= ksm(2, n - j);
                        if (res < 0) {
                            res += mod;
                        }
                        res %= mod;
                    }
                }
                if (a[i] * 2 > a[1] && a[j] * 2 > a[1]) {
                    if (a[i] + a[j] < a[1]) {
                        res -= ksm(2, n - j);
                        if (res < 0) {
                            res += mod;
                        }
                        res %= mod;
                    }
                }
            }
        }
        printf("%lld\n", res);
        return;
    }
    ans = 0;
    dfs(1);
    printf("%d\n", ans);
}
int main () {
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    int c, t;
    scanf("%d%d", &c, &t);
    while(t --) {
        solve();
    }
    return 0;
}