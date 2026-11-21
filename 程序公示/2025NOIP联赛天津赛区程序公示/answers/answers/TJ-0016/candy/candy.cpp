#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;

ll n, m;
struct C
{
	ll x, y;
};
C a[N];
inline bool cmp(C &l, C &r)
{
	return l.x<r.x;
}
ll mnval = LONG_LONG_MAX, s[N];
ll ans = 0;


int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld%lld", &a[i].x, &a[i].y);
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 1; i <= n; i++) {
		s[i] = s[i-1]+a[i].x;
	}
	for(int i = 1; i <= n; i++) {
		mnval = min(mnval, a[i].x+a[i].y);
	}
	for(int i = 0; i <= n; i++) {
		if(m >= s[i]) {
			ans = max(ans, i+((m-s[i])/mnval)*2);
		}
	}
	printf("%lld\n", ans);
	
	
	
	
	return 0;
}
