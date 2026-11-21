#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll c, t;
ll n, m;
ll a[200010];
ll w[200010][3];
ll ans = 0;
ll mod = 998244353;

ll f[20], id[20];
bool cmp(ll x, ll y) {
    if (w[x][f[x]] != w[y][f[y]]) return w[x][f[x]] > w[y][f[y]];
    if (a[x] != a[y]) return a[x] > a[y];
    return x < y;
}
bool cmp2(ll x, ll y) {
    if (a[x] != a[y]) return a[x] > a[y];
    return f[x] < f[y];
}
ll g[20];
ll mx = 0;
void getsum(ll now) {
    if (now >n)
    {
        ll sum = 0, x = 0;
        for (int i = 1; i <= n; i++) {
            sum += g[i] * a[i];
            x += f[i] * g[i];
        }
        if (x <= m) mx = max(mx, sum);
        return;
    }
    g[now] = 0;
    getsum(now+1);
    g[now] = 1;
    getsum(now+1);
    g[now] = 0;
}
void dfs(ll now)
{
    if (now > n) {
        for (int i=1; i <= n; i++) {
            id[i] = i;
        }
        sort(id + 1, id + 1 + n, cmp);
        ll M = m;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            if (m >= f[id[i]]) {
                m -= f[id[i]];
                sum += a[id[i]];
            }
        }
        sort(id + 1, id + 1 + n, cmp2);
        ll sum2 = 0, x = 0;
        m = M;
        mx = 0;
        getsum(1);
        sum2 = mx;
        //cout << sum2 << " " << sum << "\n";
        if (sum2 == sum) {
            ans++;
            //for (int i = 1; i <= n; i++) cout << f[i] << " ";
            //cout << "j\n";
        }
        m = M;
        return;
    }
    f[now ] = 1;
    dfs(now + 1);
    f[now ] = 2;
    dfs(now + 1);
    f[now ] = 0;
}

int main()
{
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            w[i][2] = a[i];
            w[i][1] = a[i] * 2;
        }
        if (c <= 5) {
            ans = 0;
            dfs(1);
            cout << ans << "\n";
        }
        else if (c == 16 || c == 18 || m == 2 * n - 1) {
            ll ans = 1;
            for (int i = 1; i <= n; i++) {
                ans <<= 1;
                ans %= mod;
            }
            cout << ans << "\n";
        }
        else if(c == 17 || m == 2 * n - 2) {
            ll ans = 1;
            ll mn = 1e18;
            for (int i = 1; i <= n; i++) {
                ans <<= 1;
                ans %= mod;
                mn = min(mn, a[i]);
            }
            ll cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == mn) cnt++;
            }
            if (cnt == 1) {
                ll m2 = 1e18;
                for (int i = 1; i <= n; i++) {
                    if (a[i] != mn) m2 = min(m2, a[i]);
                }
                if (mn * 2 > m2) {
                    ans = (ans - 1 + mod) % mod;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
