#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll p = 998244353;
ll _ , t , n , m , a[5009] , b[5009] , ans;

inline ll qp(ll a , ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p , b >>= 1;
	}
	return res;
}

inline int find(int x) {
	int l = 1 , r = n , mid , ans = n + 1;
	while (l <= r) {
		mid = l + r >> 1;
		if (a[mid] < x) r = mid - 1 , ans = mid;
		else l = mid + 1;
	}
	return ans;
}

bool check1() {
	for (int i = 1 ; i < n ; i++) if (a[i] != a[i + 1]) return 0;
	return 1;
}

void work() {
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1 , greater<int>());
	for (int i = 1 ; i <= n ; i++) b[i] = a[i] + a[i];
	ans = qp(2 , n);
	if (m == 2) {
		for (int i = 2 ; i <= n ; i++) {
			if (b[i] <= a[1]) break;
			int tmp = find(a[1] - a[i]);
			ans = (ans - qp(2 , n - tmp + 1) + p) % p;
		}
		cout << ans << "\n";
		return;
	} else if (m == 2 * n - 1) {
		cout << ans << "\n";
		return;
	} else if (m == 2 * n - 2) {
		cout << ans - (b[n] > a[n - 1] && a[n] < a[n - 1]) <<"\n";
		return;
	} else if (check1()) {
		cout << ans << "\n";
		return;
	} else cout << ans << "\n";
}


int main() {
	freopen("sale.in" , "r" , stdin);
	freopen("sale.out" , "w" , stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> _ >> t;
	while (t--) work();
	return 0;
}
