#include<bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x % y);
}

ll n, m, a[100005], b[100005];

int main() {
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    cin >> n >> m;
    ll mi = 1e18;
    for(int i = 1; i <= n; i++)scanf("%lld%lld", &a[i], &b[i]), mi = min(mi, a[i] + b[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) a[i] += a[i - 1];
    ll nw = 0, ans = 0;
    while(m >= 0) {
        ans = max(ans, nw + (upper_bound(a + 1, a + n + 1, m) - a - 1));
        m -= mi, nw += 2;
    }
    cout << ans;
    return 0;
}

