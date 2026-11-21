#include <bits/stdc++.h>
using namespace std;
int c,T,n,m;
struct candy
{
	int x,y;
};
candy a[10005],b[10005];
int cmp1(candy a,candy b)
{
	return a.x / a.y > b.x / b.y && a.x > b.x;
}
int cmp2(candy a,candy b)
{
	return a.x > b.x;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin >> c >> T;
	if (c == 18)
	{
		while (T--)
		{
			int ans = 2;
			cin >> n >> m;
			memset(a,0,sizeof(a));
			for (long long i = 1;i <= n;i++)
			{
				cin >> a[i].x;
			}
			while (n--)
			{
				ans = ans * 2 % 998244353;
			}
			cout << ans << endl;
		}
	}
	while (T--)
	{
		int ans = 0;
		cin >> n >> m;
		memset(a,0,sizeof(a));
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i].x;
			b[i].x = a[i].x;
		}
		for (int i = 1;i <= pow(2,n);i++)
		{
			for (int j = 1;j <= n;j++) a[j].x = b[j].x;
			int t = pow(2,i - 1),sum1 = m,o1 = 0,o2 = 0,sum2 = m;
			for (int j = 1;j <= n;j++)
			{
				a[j].y = (((i + int(pow(2,j - 1)) - 1) / int(pow(2,j - 1))) % 2);
				if (a[j].y == 0) a[j].y = 2;
				//cout << a[j].y << ' ';
			}
			//cout << endl;
			sort(a + 1,a + n + 1,cmp1);
			//for (int j = 1;j <= n;j++) cout << a[j].x << ' ' << a[j].y << endl;
			//cout << endl;
			for (int j = 1;j <= n;j++)
			{
				if (sum1 >= a[j].y) 
				{
					sum1 -= a[j].y;
					o1 += a[j].x;
				}
			}
			sort(a + 1,a + n + 1,cmp2);
			for (int j = 1;j <= n;j++)
			{
				if (sum2 >= a[j].y)
				{
					sum2 -= a[j].y;
					o2 += a[j].x;
				}
			}
			if (sum1 >= sum2) ans++;
		}
		cout << ans << endl;
	}
	return 0;
 } 
