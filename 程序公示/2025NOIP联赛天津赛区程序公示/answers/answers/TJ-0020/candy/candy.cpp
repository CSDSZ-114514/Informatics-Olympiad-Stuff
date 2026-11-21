#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read()
{
	ll sum = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') sum = (sum << 1) + (sum << 3) + (c ^ 48), c = getchar();
	return sum * f;
}
const ll N = 2e5 + 10, Max = 1e17;
ll n, m, a[N], b[N], mn = Max; 
ll ans, nsum;
int main()
{
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++) 
		a[i] = read(), b[i] = read(), mn = min(mn, a[i] + b[i]);
	sort(a + 1, a + n + 1);
	for(int i = 0; i <= n; i++)
	{
		nsum += a[i];
		if(nsum > m) break;
		ll nans = 0;
		nans = i + ((m - nsum) / mn) * 2;
		ans = max(ans, nans); 
	}
	cout<<ans;
	return 0;
}
/*
*/
