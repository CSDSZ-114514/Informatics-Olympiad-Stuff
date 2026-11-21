#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+3;

struct stu{
	long long int s,t;
}lst[N];

int n,f;
long long int m,k,kk;
long long int p,sum,ans;

int cmp(stu a,stu b)
{
	return a.s < b.s; 
}

int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	
	cin >> n >> m;
	sum = 0;
	ans = 0;
	p = 0;
	for (int i=1; i<=n; i++)
	{
		cin >> lst[i].s >> lst[i].t;
		k = max(k,lst[i].t) + 1;
		kk = k;
		if (sum == 0 or sum >= (lst[i].s+lst[i].t)) 
		{
			sum = lst[i].s+lst[i].t;
			if (p == 0 or p > lst[i].s) p = lst[i].s;
		}
	}
	sort(lst+1, lst+n+1, cmp);
	f = 0;
	for (int i=1; i<=n; i++)
	{
		if (p == lst[i].s) f = 1;
		if (lst[i].s*2 <= sum)
		{
			if (m >= lst[i].s) 
			{
				ans++;
				k = min(k,lst[i].t);
				m -= lst[i].s; 
			}
			else break;
		} 
		else
		{
			if (f == 1) m += p,ans--;
			if (m >= sum)
			{
				ans += 2 * (m / sum);
				m %= sum;
				if (m >= min(p,min(lst[i].s,k))) 
				{ 
					ans++;
					m -= min(p,min(lst[i].s,k));  
				}
				if(m + lst[i-1].s >= sum) ans++;
				break;
			}
			else 
			{
				m -= p;
				ans++;
				if (m >= lst[i].s) 
				{
					ans++;
					m -= lst[i].s; 
				}
				else break;
			}
			
		}
	}
	cout << ans << endl;

	return 0;
}
