#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 5e4+5, lgN = 20;

ll n, q, a[N];

ll s[N], st[N][lgN];
inline void init()
{
	int lgn = __lg(n);
	for(int i = 1; i <= n; i++) {
		s[i] = s[i-1]+a[i];
		st[i][0] = s[i];
	}
	for(int j = 1; j <= lgn; j++) {
		for(int i = 1; i+(1<<j)-1 <= n; i++) {
			st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
inline ll query(int l, int r)
{
	if(l>r) return -1e16;
	int k = __lg(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}

ull zero = 0;

inline ull solve(ll L, ll R)
{
	ull ret = 0;
	for(ll j = 1; j <= n; j++) {
		ll k = -1e16;
//		printf("deal %d:", j);
		for(int l = max(1ll,j-R+1); l<=j&&(l+L-1<=min(n,l+R-1)); l++) {
			k = max(k,query(max(j,l+L-1),min(n,l+R-1))-s[l-1]);
//			printf("check %d, [%d,%d]=%lld, query=%lld, s[l-1]=%lld\n", l, max(j,l+L-1), min(n,l+R-1), k
//			, query(max(j,l+L-1),min(n,l+R-1)), s[l-1]);
		}
//		printf("%lld ", k);
		if(k < 0){
			k = abs(k);
			k = ~zero-k+1;
			ret = ret^((ull)j*(ull)k);
		}
		else
			ret = ret^((ull)j*(ull)k);
	}
//	printf("\n");
	return ret;
}

int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	init();
	scanf("%lld", &q);
	for(int i = 1, L, R; i <= q; i++) {
		scanf("%d%d", &L, &R);
		printf("%llu\n", solve(L,R));
	}
	return 0;
}
