#include <bits/stdc++.h>
using namespace std;

#define int long long

priority_queue <int> q; 

const int N = 1e5 + 10;

struct Node
{
	int var;
	int num;
};

Node s[N << 1];

bool cmp(Node a , Node b)
{
	return (a.var * b.num < b.var * a.num);
}

signed main()
{
	freopen("candy.in" , "r" , stdin);
	freopen("candy.out" , "w" , stdout);
	
	int n , m;
	scanf("%lld %lld" , &n , &m);
	int x , y;
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%lld %lld" , &x , &y);
		s[(i << 1) - 1].num = 1;
		s[(i << 1) - 1].var = x;
		s[i << 1].num = 2;
		s[i << 1].var = x + y;
	}
	sort(s + 1 , s + (n << 1) + 1 , cmp);
	int ans = 0;
	for(int i = 1 ; i <= (n << 1) ; i++)
	{
		if(s[i].num == 1)
		{
			if(m >= s[i].var)
			{
				q.push(s[i].var);
				ans++;
				m -= s[i].var;
			}
		}
		else
		{
			ans += (m / s[i].var) << 1;
			m %= s[i].var;
			while(!q.empty())
			{
				if(q.top() + m >= s[i].var)
				{
					m = m + q.top() - s[i].var;
					ans++;
					q.pop();
				}
				else
				{
					break;
				}
			}
		}
	}
	printf("%lld" , ans);

	return 0;
}
