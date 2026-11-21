#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,p;
struct candy
{
	long long x,y;
};
candy a[1000005],b[1000005];
int cmp1(candy a,candy b)
{
	return (a.x + a.y) < (b.x + b.y);
}
int cmp2(candy a,candy b)
{
	return a.x < b.x;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1;i <= n;i++)
	{
		cin >> a[i].x >> a[i].y;
		b[i].x = a[i].x;
		b[i].y = a[i].y;
	}
	sort(a + 1,a + n + 1,cmp1);
	sort(b + 1,b + n + 1,cmp2);
	for (long long i = 1;i <= n;i += 2)
	{
		if ((a[1].x + a[1].y) <= b[i].x + b[i + 1].x || m < min((a[1].x + a[1].y),(b[i].x + b[i + 1].x)) || i == n)
		{
			p = i;
			break;	
		}
		else
		{
			ans += 2;
			m -= (b[i].x + b[i + 1].x);
		} 
	}
	ans += 2 * (m / (a[1].x + a[1].y));
	m = m - (m / (a[1].x + a[1].y) * (a[1].x + a[1].y));
	for (long long i = p - 1;i >= 1;i--)
	{
		if (m + b[i].x - (a[1].x + a[1].y) >= 0)
		{
			ans++;
			p--;
			m = m + b[i].x - (a[1].x + a[1].y);
		}
		else break;
	}
	if (m >= min(a[1].x,b[p].x)) 
	{
		ans++;
		m -= min(a[1].x,b[p].x);
	}
	if (m >= max(a[1].x,b[p].x)) ans++;
	cout << ans;
	return 0;
 } 
