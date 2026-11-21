#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n , m , x[100009] , y[100009] , s[100009] , minn = 1e18 + 1 , p = 1 , tmp , ans;

int main() {
	freopen("candy.in" , "r" , stdin); freopen("candy.out" , "w" , stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) cin >> x[i] >> y[i] , minn = min(minn , x[i] + y[i]);
	sort(x + 1 , x + n + 1);
	for (int i = 1 ; i <= n ; i++) s[i] = s[i - 1] + x[i];
	while (p <= n) {
		int nxtp = upper_bound(s + p , s + n + 1 , minn + tmp) - s - 1;
		if (nxtp == p) break;
		tmp += s[nxtp] - s[p - 1] , ans += nxtp - p + 1 , p = nxtp + 1;
	}
	m -= tmp , ans += (m / minn) * 2 , m -= (m / minn) * minn;
	for (int i = p ; i <= n ; i++) {
		if (x[i] > m) break;
		m -= x[i] , ans++;
	}
	cout << ans;
	return 0;
}
