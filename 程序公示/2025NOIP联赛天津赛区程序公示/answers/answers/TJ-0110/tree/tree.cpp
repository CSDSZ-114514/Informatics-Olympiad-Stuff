#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll T;
ll n, m;
vector<vector<ll>> t(200010);

ll f[20];
ll ans = 0;
ll mx = 0;
ll mex(ll x)
{
    ll ret = 0;
    while (x & 1) {
        x >>= 1;
        ret++;
    }
    return ret;
}
ll solve(ll p)
{
    ll c = 0;
    for (auto i : t[p]) {
        c |= solve(i);
    }
    c |= (1 << f[p]);
    ans += mex(c);
    return c;
}
void dfs(ll now)
{
    if (now > n) {
        ans = 0;
        solve(1);
        mx = max(mx, ans);
        return;
    }
    for (int i = 0; i < n; i++) {
        f[now] = i;
        dfs(now + 1);
        f[now] = 0;
    }
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        t = vector<vector<ll>>(n + 5);
        for (int i = 2; i <= n; i++) {
            ll p;
            cin >> p;
            t[p].push_back(i);
        }
        mx = 0;
        dfs(1);
        cout << mx << "\n";
    }
    return 0;
}
