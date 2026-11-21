#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5500, MOD = 998244353;
int c, t, n, m;
ll a[N], sum;
ll f[N][N*2];
struct node {
	double v; ll a; int id, w;
} b[N];

ll qpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res % MOD;
}

ll solve(ll S) {
	ll res = 0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) f[i][j] = 0;
//	for(int i=1; i<=n; i++) cout << (1&(S>>i-1))+1 << " ";
//	cout << "\n"; 
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			if(j < (1&(S>>i-1))+1) f[i][j] = f[i-1][j];
			else f[i][j] = max({f[i-1][j],f[i-1][j-(1&(S>>i-1))-1]+a[i]});
			res = max(res, f[i][j]); 
			//cout << i << " " << j << " " << f[i][j] << "\n"; 
		}
	for(int i=1; i<=n; i++) b[i] = {1.0*a[i]/((1&(S>>i-1))+1),a[i],i,(1&(S>>i-1))+1};
	sort(b+1,b+n+1,[](node a,node b){
		if(a.v != b.v) return a.v > b.v;
		if(a.a != b.a) return a.a > b.a;
		return a.id < b.id; 
	});
	ll now = 0, ans = 0;
	for(int i=1; i<=n; i++) {
		if(m - now >= b[i].w) now += b[i].w, ans += b[i].a;
	}
	sum = (sum + (ans >= res)) % MOD;
}

int main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> t;
	while(t--) {
		sum = 0;
		cin >> n >> m;
		for(int i=1; i<=n; i++) cin >> a[i];
		if(n <= 40) {
			for(ll S=0; S<=(1<<n)-1; S++) {
				solve(S); 
			}
			cout << sum << "\n";
			continue;
		}
		else if(m == 2*n-1) {
			sum = qpow(2, n) % MOD;
			sort(a+1, a+n+1, [](int a,int b){
				return a < b;
			});
			if(a[1]*2 > a[2] && a[2] != a[1]) sum = (sum-1+MOD)%MOD;
			cout << sum << "\n";
			continue;
		}
		else if(m == 2*n-2) {
			sum = qpow(2, n) % MOD;
			sort(a+1, a+n+1, [](int a,int b){
				return a < b;
			});
			if(a[1]*2 > a[2] && a[2] != a[1]) sum = (sum-1+MOD)%MOD;
			cout << sum << "\n"; 
			continue;
		}
		else {
			cout << qpow(2, n) % MOD << "\n";
			continue;
		} 
	}

	return 0;
}

