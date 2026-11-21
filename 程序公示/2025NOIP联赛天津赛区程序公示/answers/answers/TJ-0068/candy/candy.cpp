#include <bits/stdc++.h>
using namespace std;
/*namespace p2{
	const int MAXN = 1e5 + 10;
	int n, w0[MAXN], w1[MAXN];
	long long m;
	int dfs(int p, int nxt, int usd){
		if(p > n) return 0;
		int ans = dfs(p + 1, 1, usd);
		int cost = (nxt & 1) ? w1[p] : w0[p];
		if(usd + cost <= m) ans = max(ans, dfs(p, nxt ^ 1, usd + cost) + 1);
		return ans;	
	}
	void workA(){
		int mi = 0x3f3f3f3f;
		for(int i = 1; i <= n; i++) mi = min(mi, w0[i]);
		long long ans = m/mi;
		printf("%lld", ans);
	}
	void solve(){
		scanf("%d%lld", &n, &m);
		bool typeA = true;
		for(int i = 1; i <= n; i++){
			scanf("%d%d", &w1[i], &w0[i]);
			typeA &= (w1[i] == w0[i]);
		}
		if(typeA) workA();
		else printf("%d", dfs(1, 1, 0));
	}
}*/
namespace p1{
	const int MAXN = 1e3 + 10;
	const int MAXM = 1e4 + 10;
	int n, w0[MAXN], w1[MAXN];
	long long m;
	int hasmem[MAXN][2][MAXM];
	int dfs(int p, int nxt, int usd){
		if(p > n) return 0;
		if(hasmem[p][nxt][usd]) return hasmem[p][nxt][usd];
		int ans = dfs(p + 1, 1, usd);
		int cost = (nxt & 1) ? w1[p] : w0[p];
		if(usd + cost <= m) ans = max(ans, dfs(p, nxt ^ 1, usd + cost) + 1);
		return hasmem[p][nxt][usd] = ans;	
	}
	void workA(){
		int mi = 0x3f3f3f3f;
		for(int i = 1; i <= n; i++) mi = min(mi, w0[i]);
		long long ans = m/mi;
		printf("%lld", ans);
	}
	void solve(){
		scanf("%d%lld", &n, &m);
		bool typeA = true;
		for(int i = 1; i <= n; i++){
			scanf("%d%d", &w1[i], &w0[i]);
			typeA &= (w1[i] == w0[i]);
		}
		if(typeA) workA();
		else printf("%d", dfs(1, 1, 0));
	}
}
int main(){
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	p1::solve();
	return 0;
} 
