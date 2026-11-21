// stosto pingceji orzorz
// buyao WA TLE RE a
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),END##i=(b);i<=END##i;++i)
#define pre(i,a,b) for(int i=(a),END##i=(b);i>=END##i;--i)
using namespace std;
typedef long long ll;
// Problem: query
const int N = 5e4 + 5;
int n, qq; ll a[N]; deque<int> q;
int main()
{
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]), a[i] += a[i - 1];
	scanf("%d", &qq);
	while (qq --)
	{
		int l, r; scanf("%d%d", &l, &r);
		unsigned long long ans = 0;
		rep(i, 1, n)
		{
			long long res = -0x3f3f3f3f3f3f3f3f;
			q.clear();
			rep(j, i - r, i - l - 1)
			{
				while (q.size() && a[q.back()] > a[j]) q.pop_back();
				q.push_back(j);
			}
			rep(j, i, i + r - 1)
			{
				while (q.size() && q.front() < j - r) q.pop_front();
				if (j - l < i)
				{
				while (q.size() && a[q.back()] > a[j - l]) q.pop_back();
				q.push_back(j - l);
				}
				res = max(res, a[j] - a[q.front()]);
			}
			ans ^= 1llu * i * (unsigned long long)res;
		}
		printf("%llu\n", ans);
	}
	return 0;
}

