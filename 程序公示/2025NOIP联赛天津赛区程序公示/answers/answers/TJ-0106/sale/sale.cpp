#include <bits/stdc++.h>
using namespace std;
cntst long long int M = 998244353;

int c,t,n,m,a;
long long int ans,k;

int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> m;
		k = 1;
		for (int i = 0; i<=n; i++)
		{
			if(i == 0 or i == n) ans++;
			else 
			{
				k *= (n-i+1);
				ans += k;
				ans %= M; 
			}
		} 
		cout << ans << endl;
	}
	
	return 0;
}
