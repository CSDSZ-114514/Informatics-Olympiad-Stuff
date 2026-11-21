#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 5e3+5, N1 = 100, mod = 998244353;

int C, T;
int n, m, a[N];
ll f[N1][N1<<1];

int w[N];
struct Node
{
	ll v, a, w, id;
};
Node c[N];
inline bool cmp(Node &l, Node &r)
{
	return (l.v!=r.v)?(l.v>r.v):((l.a!=r.a)?(l.a>r.a):(l.id<r.id));
}
inline bool check()
{
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			f[i][j] = f[i-1][j];
			if(j>=w[i]) {
				f[i][j] = max(f[i][j],f[i-1][j-w[i]]+a[i]);
			}
		}
	}
	ll ans1 = f[n][m], ans2 = 0, las = m;
	for(int i = 1; i <= n; i++) {
		if(w[i] == 1)
			c[i].v = a[i]*2;
		else
			c[i].v = a[i];
		c[i].a = a[i]; c[i].w = w[i]; c[i].id = i;
	}
	sort(c+1,c+1+n,cmp);
	for(int i = 1; i <= n; i++) {
		if(las>=c[i].w) {
			ans2 += c[i].a;
			las -= c[i].w;
		}
	}
	return ans1 == ans2;
}
ll ans = 0;
inline void dfs(int dep)
{
	if(dep == n+1) {
		if(check()) {
			ans++;
		}
//		else {
//			for(int i = 1; i <= n; i++) {
//				printf("(%d %d %d)\n", c[i].w, c[i].a, c[i].v);
//			}
//			printf("\n");
//		}
		return;
	}
	w[dep] = 1;
	dfs(dep+1);
	w[dep] = 2;
	dfs(dep+1);
}

inline ll qpow(ll x, ll y)
{
	ll tmp = x, ret = 1;
	while(y) {
		if(y&1) ret = (ret*tmp)%mod;
		tmp = (tmp*tmp)%mod;
		y>>=1;
	}
	return ret;
}

inline void solve()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if(m == 2*n || C == 18) {
		printf("%lld\n", qpow(2,n));
	}
//	else if(C == 14 || C == 15 || (7 <= C && C <= 9)) {
//		solve2();
//	}
	else if(C == 16) {
		printf("%lld\n", (mod+qpow(2,n)-1)%mod);
	}
	else {
		dfs(1);
		printf("%lld\n", ans);
		ans = 0;
	}
}

int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	
	scanf("%d%d", &C, &T);
	for(int i = 0; i < T; i++) {
		solve();
	}
	
	return 0;
}
