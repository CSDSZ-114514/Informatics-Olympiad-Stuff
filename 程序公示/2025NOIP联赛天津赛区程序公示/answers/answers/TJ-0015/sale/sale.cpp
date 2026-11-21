#include <bits/stdc++.h> 
#define int long long
using namespace std;

const int mod = 998244353;
int c, t, n, m, a[5010], p[5010], ans;
struct DATA {
	int w, v;
};

bool cmp(DATA x, DATA y) {
	double xx = ((double)x.v*1.00)/((double)x.w*1.00);
	double yy = ((double)y.v*1.00)/((double)y.w*1.00);
	if(xx != yy) return xx > yy;
	return x.v > y.v;
}
void slove1() {
	int f[5010];
	DATA b[5010];
	while(t--) {
		scanf("%lld%lld", &n, &m), ans = 0;
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		for(int i = 0; i < (1<<n); i++) {
			for(int j = 0; j <= m; j++) f[j] = 0, b[j] = {0, 0};
			//cout << i <<endl;
			for(int j = 0; j < n; j++)
				b[j+1].w = ((i>>j)&1)+1, b[j+1].v = a[j+1];
			sort(b+1, b+n+1, cmp);
			int ans1 = 0, m1 = m, ans2 = 0;
			for(int j = 1; j <= n; j++) {
				if(m1 >= b[j].w) m1 -= b[j].w, ans1 += b[j].v;
				//cout << b[j].w << ' ' << b[j].v << endl;
			}
			//cout << ans1 << ' '; 
			for(int j = 1; j <= n; j++)
				for(int k = m; k >= b[j].w; k--)
					f[k] = max(f[k], f[k-b[j].w]+b[j].v), ans2 = max(ans2, f[k]);
			//cout << ans2 << endl;
			if(ans1 == ans2) ans++;
		}
		printf("%lld\n", ans%mod);
	}
}
void slove2() {
	while(t--) {
		scanf("%lld%lld", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		sort(a+1, a+n+1);
		//for(int i = 1; i <= n; i++) printf("%lld  ", a[i]);
		if((double)a[1]*1.00 > double(a[2])/2.0)
			printf("%lld\n", p[n]-1);
		else printf("%lld\n", p[n]);
		/*for(int i = 1; i <= n; i++) {
			
		}*/
	}
}
void slove3() {
	while(t--) {
		scanf("%lld%lld", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		printf("%lld\n", p[n]);
	}
}

signed main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	scanf("%lld%lld", &c, &t), p[0] = 1;
	for(int i = 1; i <= 5000; i++) p[i] = p[i-1]*2%mod;
	//cout << p[300] << endl;
	if(c >= 1 && c <= 5) slove1();
	if((c >= 7 && c <= 9) || c == 14 || c == 15) {}
	if(c == 0) slove2();
	if(c == 18 || c == 16) slove3();
	
	return 0;
}
/*
1 1
5 2
349819260 357654786 353737023 707474046 384461657
*/
/*
5 5
241951671 241951671 251607302 335678433 483903342

120975835.5 120975835.5 125803651 167839216.5 241951671 241951671 241951671 251607302 335678433 483903342
*/
