// stosto pingceji orzorz
// buyao WA TLE RE a
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),END##i=(b);i<=END##i;++i)
#define pre(i,a,b) for(int i=(a),END##i=(b);i>=END##i;--i)
using namespace std;
typedef long long ll;
// Problem: candy
// its not knapsack but greedy!!!
const int N = 1e5 + 5;
int n; ll m, a[N];
int main()
{
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	ll res = 0x3f3f3f3f3f3f3f3fll, tans = 0, ans = 0;
	rep(i, 1, n)
	{
		ll t; scanf("%lld%lld", &a[i], &t);
		res = min(res, t + a[i]);
	}
	sort(a + 1, a + n + 1);
	int p;
	ll t = m / res, tt = tans + t * 2, tm = m - t * res;
	if (tm >= a[1]) ++ tt;
	ans = max(ans, tt);
	for (p = 1; p <= n; ++ p)
	{
		++ tans, m -= a[p];
		if (m < 0) break;
		ll t = m / res, tt = tans + t * 2, tm = m - t * res;
		if (p < n && tm >= a[p + 1]) ++ tt;
		ans = max(ans, tt);
	}
	printf("%lld", ans);
	return 0;
}

