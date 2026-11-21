#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 10;
struct node {
	ll a, b;
} a[N];
ll n, m;

int main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i].a >> a[i].b;
	sort(a+1, a+n+1, [](node a,node b){
		return a.a+a.b < b.a+b.b;
	});
	
	ll now = 0, ans = 0;
	ll tmp = a[1].a + a[1].b, res = a[1].a; a[1].a = 1e10;
	sort(a+1, a+n+1, [](node a,node b){
		return a.a < b.a;
	});
	int las = 0;
	//cout << tmp << " " << a[2].a + a[2].b << "\n"; 
	for(int i=1; i<n; i++) {
		if(a[i].a * 2 <= tmp) now += a[i].a, ans++, las = i;//res = min(res, a[i].b);
		//if(a[i].a != 1e9+1) res = min(res, a[i].a); 
		if(now >= m) break; 
	}
	ll ans2 = ans - 1, now2 = now - a[las].a;
	
	if(now < m) ans += (m-now) / tmp * 2,  now += ((m-now) / tmp) * tmp;
	//cout << now << " " << m << " " << res << "\n";
	if(now < m && m - now >= res) ans++;
	
	if(now2 < m) ans2 += (m-now2) / tmp * 2,  now2 += ((m-now2) / tmp) * tmp;
	//cout << now << " " << m << " " << res << "\n";
	if(now2 < m && m - now2 >= res) ans2++;
	
	cout << max(ans, ans2);

	return 0;
}








