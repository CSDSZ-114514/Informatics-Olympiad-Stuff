#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
const int N = 5005, mod = 998244353;

int __c, __t;
int n, m;
int a[N];

int ans;

bool cmp(pii p, pii q) {
	return p.first > q.first;
}

int dfs(int idx, int val, int p, int u) {
	if (idx == n) {
		return val;
	}
	int res = 0;
	if (u & (1<<idx) && p >= 1) {
		res = dfs(idx+1, (val + a[idx]), p - 1, u);
	} else if (p >= 2) {
		res = dfs(idx+1, (val + a[idx]), p - 2, u);
	}
	res = max(res, dfs(idx+1, val, p, u));
	return res;
}

void check(int u) {
	vector<pii> b;
	for(int i = 0; i < n; i++) {
		if ((1<<i) & u) b.push_back((pii){a[i], 1});
		else b.push_back((pii){a[i] / 2, 2});
	}
	sort(b.begin(), b.end(), cmp);
	int p = m, res = 0;
	for(int i = 0; i < n; i++) {
		if (p >= b[i].second) {
			res = (res + b[i].first * b[i].second);
//			cout << res << endl;
			p -= b[i].second;
		}
	}
//	cout << res << ' ' << dfs(0, 0, m, u) << endl;
	if (res == dfs(0, 0, m, u)) {
		
		ans++;
	}

}

void solve() {
//	cout << 's';
	ans = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = 2 * a[i];
	}
	
	for(int i = 0; i < (1<<n); i++) {
		check(i);
	}
	cout << ans << endl;
}

signed main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	cin >> __c >> __t;
	while (__t--) {
		solve();
//		break;
	}
	return 0;
}
