#include <bits/stdc++.h>
using namespace std;
namespace p1{
	const int MAXN = 5e4 + 10;
	long long MOD = 1ll << 64; 
	int n, a[MAXN], q, lj, rj;
	long long s[MAXN], ans;
	
	long long sum(int l, int r){
		return s[r] - s[l - 1];
	}
	
	long long mod(long long x){
		if(x >= 0) return x % MOD;
		return MOD - mod(-x);
	}
	
	void workA(){
		int k = lj;
		long long ans = 0;
		for(int i = 1; i <= n; i++){
			long long res = 0;
			for(int j = i; j <= n; j++){
				int sp = j - k + 1;
				if(sp < 1) continue;
				if(sp > i) break;
				res = max(res, sum(sp, j));
			}
			//printf("i=%d res=%lld\n", i, res);
			ans = ans ^ (i * res);
		}
	}
	void solve(){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			s[i] = a[i] + s[i - 1];
		}
		scanf("%d", &q);
		while(q--){
			scanf("%d%d", &lj, &rj);
			if(lj == rj) workA();
			printf("%lld\n", ans);
		}	
	}
}
int main(){
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	p1::solve();
	return 0;
} 
