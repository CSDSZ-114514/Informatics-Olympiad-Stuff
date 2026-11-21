#include <bits/stdc++.h>
using namespace std;

namespace p2{
	const int MAXN = 40;	//duo ce
	const int MAXM = 2 * MAXN;
	const int mod = 998244353;
	int c, t, n, m, ans;
	struct Candy{
		int a, w;
	}can[MAXN];
	void opt(int x, int k){
		if(k) opt(x >> 1, k - 1);
		printf("%d", x & 1);
	}
	int pric(int &p, long long &i){
		/*printf("p = %d ind = ", p);
		opt(i, n);
		printf("\n");*/
		int res = (1 & (i >> (p - 1))) + 1;
		//printf("res = %d\n", res);
		assert(res == 1 || res == 2);
		return res;
	}
	long long hasmem[MAXN][MAXM];
	long long dfs(int p, long long usd, long long &i){
		if(p > n) return 0;
		if(hasmem[p][usd]) return hasmem[p][usd];
		long long ans = dfs(p + 1, usd, i);
		if(usd + pric(p, i) <= m)
			ans = max(ans, dfs(p + 1, usd + pric(p, i), i) + can[p].a);
		return hasmem[p][usd] = ans;
	}
	bool cmp(const Candy &x, const Candy &y){
		double vx = (double)x.a / x.w;
		double vy = (double)y.a / y.w;
		if(vx != vy) return vx > vy;
		if(x.a != y.a) return x.a > y.a;
		return true; // ok?
	}
	long long calc(long long &ind){
		Candy tmp[MAXN];
		for(int i = 1; i <= n; i++){
			tmp[i] = can[i];
			tmp[i].w = pric(i, ind);
		}
		sort(tmp + 1, tmp + 1 + n, cmp);
		long long usd = 0, res = 0;
		for(int i = 1; i <= n; i++)
			if(usd + tmp[i].w <= m) usd += tmp[i].w, res += tmp[i].a;
		return res; 
	}	 
	void solve(){
		scanf("%d%d", &c, &t);
		while(t--){
			scanf("%d%d", &n, &m);
			for(int i = 1; i <= n; i++){
				scanf("%d", &can[i].a);
			}
			/*0 -> 1 , 1 -> 2*/
			long long bound = (1 << n) - 1;
			ans = 0;
			for(long long ind = 0; ind <= bound; ind++){
				//opt(ind, n);
				memset(hasmem, 0, sizeof(hasmem));
				long long tar = dfs(1, 0, ind);
				//printf(" max=%lld his=%lld", tar, calc(ind));
				if(calc(ind) == tar){
					ans = (ans + 1) % mod;
					//printf(" true");
				}
				//printf("\n");
			}
			printf("%d\n", ans);
		}
	}
}

int main(){
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	p2::solve();
	return 0;
} 
