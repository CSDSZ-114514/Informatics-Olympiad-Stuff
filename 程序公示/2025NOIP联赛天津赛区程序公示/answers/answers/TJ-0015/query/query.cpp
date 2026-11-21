#include <bits/stdc++.h> 
#define int long long
using namespace std;

int n, q, a[50010], s[50010], ans[50010];
map<pair<int,int>, __int128> mp;
struct TREE {
	int l, r, v;
} t[200010];

void pushup(int u) {
	t[u].v = max(t[u<<1].v, t[u<<1|1].v);
}
void build(int u, int l, int r) {
	t[u].l = l, t[u].r = r;
	if(l == r) {
		t[u].v = s[l];
		return;
	}
	int mid = (l+r)>>1;
	build(u<<1, l, mid), build(u<<1|1, mid+1, r);
	pushup(u);
}
int query(int u, int l, int r) {
	if(t[u].l >= l && t[u].r <= r) return t[u].v;
	int mid = (t[u].l+t[u].r)>>1, res = -0x3f3f3f3f3f3f3f3f;
	if(l <= mid) res = max(res, query(u<<1, l, r));
	if(r > mid) res = max(res, query(u<<1|1, l, r));
	return res; 
}
void write(__int128 x) {
	if(x < 10) {
		putchar(x%10+'0');
		return;
	}
	write(x/10), putchar(x%10+'0');
}

signed main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	scanf("%lld", &n);
	__int128 mod = 1;
	for(int i = 1; i <= 64; i++) mod *= 2; 
	for(int i = 1; i <= n; i++) 
		scanf("%lld", &a[i]), s[i] = s[i-1]+a[i];
	build(1, 1, n);
	scanf("%lld", &q);
	for(int i = 1; i <= q; i++) {
		int l, r;
		scanf("%lld%lld", &l, &r);
		if(mp[{l, r}]) {
			printf("%lld\n", mp[{l, r}]);
			continue;
		}
	//	cout << 111 << endl;
		for(int j = 1; j <= n; j++) {
			ans[j] = -0x3f3f3f3f3f3f3f3f;
			cout << j << endl;
			for(int k = min(j-r+1, 1ll); k <= min(j+r-1, n); k++) {
				if(n-k+1 < l) break;
				ans[j] = max(ans[j], query(1, k+l-1, min(n, k+r-1))-s[k]);
			}
		}
		//cout << 111 << endl;
		__int128 _ans = 0;
		for(int j = 1; j <= n; j++)
			_ans ^= (__int128(j)*__int128(ans[j])%mod);
		if(_ans < 0) printf("-");
		write(_ans), printf("\n"), mp[{l, r}] = _ans;
	} 
	
	return 0;
}

/*
4
2 4 -5 1
3
1 2
3 4
1 4

*/
