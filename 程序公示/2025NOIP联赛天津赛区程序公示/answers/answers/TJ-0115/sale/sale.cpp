// stosto pingceji orzorz
// buyao WA TLE RE a
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),END##i=(b);i<=END##i;++i)
#define pre(i,a,b) for(int i=(a),END##i=(b);i>=END##i;--i)
using namespace std;
typedef long long ll;
// Problem: sale
// i hate counting
const int N = 5005, M = 998244353;
int C, T, n, m, a[N];
int qpow(int a, int b)
{
	int res = 1;
	for (; b; b >>= 1, a = 1ll * a * a % M) if (b & 1) res = 1ll * res * a % M;
	return res;
}
namespace m2 // m==2
{
	void sol()
	{
		sort(a + 1, a + n + 1);
		int ans = 2;
		rep(i, 1, n) rep(j, i + 1, n)
		{
			// after i except j must be 2, but a[n] / 2 must < a[j]
			if (a[j] * 2 <= a[n]) continue;
			if (a[i] + a[j] < a[n]) continue;
			(ans += qpow(2, i - 1)) %= M;
		}
		printf("%d\n", ans);
	}
}
namespace aandm2n1 // A & m == 2n - 1
{
	void sol()
	{
		printf("%d\n", qpow(2, n));
	}
}
namespace m2n2 // m == 2n - 2
{
	void sol()
	{
		sort(a + 1, a + n + 1);
		int ans = qpow(2, n);
		rep(i, 1, n)
		{
			if (a[i] * 2 < a[n]) -- ans;
		}
		printf("%d\n", ans);
	}
}
namespace bf
{
	struct candy
	{
		int a, b;
		bool operator<(const candy o) const
		{
			return a * 2 / b == o.a * 2 / o.b ? a < o.a : a * 2 / b < o.a * 2 / o.b;
		}
	} b[N];
	ll f[N << 1];
	void sol()
	{
		int ans = 0;
		rep(i, 0, (1 << n) - 1)
		{
			rep(j, 1, n) b[j] = {a[j], (i >> (j - 1) & 1) + 1};
			sort(b + 1, b + n + 1);
			int t = m; ll res = 0;
			pre(j, n, 1)
			{
				if (t - b[j].b < 0) continue;
				t -= b[j].b; res += b[j].a;
			}
			rep(j, 0, m) f[j] = 0;
			rep(j, 1, n) pre(k, m, b[j].b) f[k] = max(f[k], f[k - b[j].b] + b[j].a);
//			assert(res <= *max_element(f, f + m + 1));
			if (res == *max_element(f, f + m + 1)) ++ ans;
		}
		printf("%d\n", ans);
	}
}
int main()
{
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	scanf("%d%d", &C, &T);
	while (T --)
	{
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", &a[i]);
		if (7 <= C && C <= 9 || C == 14 || C == 15) m2::sol();
		else if (C == 16 || C == 18) aandm2n1::sol();
		else if (C == 17) m2n2::sol();
		else bf::sol();
	}
	return 0;
}

