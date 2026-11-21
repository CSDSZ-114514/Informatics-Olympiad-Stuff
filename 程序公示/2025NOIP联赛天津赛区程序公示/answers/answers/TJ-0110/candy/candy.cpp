#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n, m;
pair<ll,ll> p[200010];
ll id[200010];

int main()
{
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    cin >> n >> m;
    ll ans = 0, mn = 1e18;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
        mn = min(mn, p[i].first + p[i].second);
    }/*
    if (0)
    {
        vector<ll> c(n + 10);
        for (int i = 1; i <= n; i++) {
            c[i] = p[i].first + p[i].second;
        }
        sort(c.begin() + 1, c.begin() + 1 + n);

        return 0;
    }*/
    sort(p + 1, p + 1 + n);
    vector<pair<ll,ll>> v;
    for (int i = 1; i <= n; i++) {
        if (p[i].first * 2 < mn && m >= p[i].first) {
            m -= p[i].first;
            v.push_back({p[i].first, i});
        }
    }
    ll len = v.size();
    ll now = 0, lst = 0;
    for (auto i : v) {
        now++;
        //cout << i.first << " ";
        if ( now == len) {
             m += i.first;
        }
        else {
            ans++;
            swap(p[i.second].first, p[i.second].second);
        }
    }
    ans += (m / mn) * 2;
    m %= mn;
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (m >= p[i].first) {
            m %= p[i].first;
            ans++;
            swap(p[i].first, p[i].second);
        }
    }
    //cout << "\n" << mn << "\n";
    cout << ans;
    return 0;
}
