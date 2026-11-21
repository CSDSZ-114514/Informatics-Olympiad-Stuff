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
const ll N = 5500, mod = 998244353;
ll n, m;
struct inform
{
	ll val, w;
}a[N];
bool cmp(inform A, inform B)
{
	if(A.val == B.val) return A.w < B.w;
	return A.val > B.val;
}
ll jie[N], njie[N];
ll ksm(ll a, ll b)
{
	ll ans = 1;
	while(b)
	{
		if(b & 1) ans = ans * a, ans %= mod;
		a = a * a, a %= mod;
		b /= 2;
	}
	return ans;
}
void Get()
{
	jie[0] = 1;
	for(int i = 1; i <= n; i++) jie[i] = jie[i - 1] * i % mod;
	njie[n] = ksm(jie[n], mod - 2);
	for(int i = n - 1; i >= 0; i--) njie[i] = njie[i + 1] * (i + 1) % mod;
}
ll C(ll n, ll m)
{
	if(m > n) return 0;
	return jie[n] * njie[m] % mod * njie[n - m] % mod;
}
ll hz[N];
void solve()
{
	n = read(); m = read();
	Get();
	for(int i = 1; i <= n; i++) a[i].val = read(), a[i].w = i;
	for(int i = 0; i <= n + 1; i++) hz[i] = 0;
	sort(a + 1, a + n + 1, cmp); 
	for(int i = n; i >= 1; i--) hz[i] = hz[i + 1] + ksm(2, n - i), hz[i] %= mod; 
//	for(int i = 1; i <= n; i++) cout<<a[i].val<<" ";
//	cout<<"\n\n";
	ll ans = ksm(2, n);
//	cout<<jie[3]<<"\n";
	a[n + 1].val = 0, a[n + 1].w = n + 1;
//	cout<<"---"<<"\n\n";
	for(int j = 1; j <= n; j++) // 第一个放不进去的2, 即 > a[j].val / 2的恰好和为m - 1 
	{
		ll mx = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i].val * 2 > a[j].val) mx = i;
			else break;
		}
		ll l = n + 1;
		for(int i = j - 1; i <= mx; i++)// 倒数第二个1
		{
			// 从l开始a[i].val + a[l].val < a[j].val
			if(i == j || i <= 0) continue;
			while(l - 1 >= mx + 1 && a[l - 1].val + a[i].val < a[j].val) 
				l--;
			ll nw, lt;// nw是已经填了多少数, lt是有多少数可变 
			if(j > i) nw = j - 1, lt = i - 1;
			else nw = j - 1 + 1, lt = i - 1 - 1; 
//			cout<<j<<" "<<i<<" "<<" "<<nw<<" "<<lt<<" "<<mx<<"\n";
			ll znm = m - 1;
			if(nw > znm || nw + lt < znm) continue;
			ll xi = C(lt, znm - nw), nans = 0;
//			for(int k = mx + 1; k <= n; k++) //最后一个1
//			{
//				if(a[i].val + a[k].val < a[j].val)
//				{
//					nans = nans + xi * ksm(2, n - k) % mod;
//				}
//			}
			nans = nans + xi * hz[l] % mod; nans %= mod;
			if(a[j].val > a[i].val) nans += xi; // 还可能全填2 
//			cout<<j<<" "<<i<<" "<<mx<<" "<<nans<<" "<<xi<<"\n";
			ans = ans - nans; ans += mod; ans %= mod;
		} 
	} 
	cout<<ans<<"\n";
}
int main()
{
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	ll c = read(), t = read();
	while(t--) solve();
	return 0;
}
/*
0 2
5 5
483903342 335678433 241951671 241951671 251607302
5 2
314776864 314776864 569094884 254318020 284547442
*/
