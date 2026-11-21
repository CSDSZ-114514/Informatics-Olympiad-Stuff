#include<iostream>
#include<algorithm>
using namespace std;

int n, m, mn = 1e9, dp[100005], a[100005], w[100005], x[100005], y[100005];
bool flag = true;

int main()
{
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		if(x[i] != y[i]) flag = false;
		else mn = min(mn, x[i]);
	}
	if(flag == true)
	{
		cout << m / mn << endl;
		return 0;
	}
	else
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			int sum = 0;
			for(int j = 1; j <= (m / (x[i] + y[i])) * 2 + 2; j++)
			{
				if(j % 2 == 1) sum += x[i];
				else sum += y[i];
				a[++cnt] = sum;
				w[cnt] = j;
			}
		}
		for(int i = 1; i <= cnt; i++)
			for(int j = m; j >= a[i]; j--)
				dp[j] = max(dp[j], dp[j - a[i]] + w[i]);
		cout << dp[m] << endl;
	}
	
	
	return 0;
}
