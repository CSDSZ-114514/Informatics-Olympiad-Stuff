#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5010;
const int M = 998244353;

struct Node
{
	int v;
	int mon;
	int id;
};

int cost[N];

Node s[N];

int dp1[2][N];

int pw[N];

bool cmp1(Node a , Node b)
{
	if(a.v * b.mon != b.v * a.mon)
	{
		return a.v * b.mon > b.v * a.mon;
	}
	else
	{
		return (a.v == b.v ? a.id < b.id : a.v > b.v);
	}
}

signed main()
{
	freopen("sale.in" , "r" , stdin);
	freopen("sale.out" , "w" , stdout);
	int C , T;
	int n , m;
	
	scanf("%lld %lld" , &C , &T);
	if(C <= 5)
	{
		while(T--)
		{
			scanf("%lld %lld" , &n , &m);
			for(int i = 1 ; i <= n ; i++)
			{
				scanf("%lld" , &cost[i]);
			}
			int maxn = 0;
			int ans = 0;
			for(int i = 0 ; i <= (1 << n) - 1 ; i++)
			{
				for(int j = 1 ; j <= n ; j++)
				{
					s[j].v = cost[j];
					s[j].id = j;
					s[j].mon = (((1 << (j - 1)) & i) == 0 ? 1 : 2);
				}
				sort(s + 1 , s + n + 1 , cmp1);
				int cnt = 0;
				int now = m;
				for(int j = 1 ; j <= n ; j++)
				{
					if(s[j].mon <= now)
					{
						cnt += s[j].v;
						now -= s[j].mon;
					}
				}
				memset(dp1[0] , 0 , sizeof(dp1[0]));
				for(int j = 1 ; j <= n ; j++)
				{
					for(int k = 0 ; k < s[j].mon ; k++)
					{
						dp1[j & 1][k] = dp1[(j & 1) ^ 1][k];
					}
					for(int k = s[j].mon ; k <= m ; k++)
					{
						dp1[j & 1][k] = max(dp1[(j & 1) ^ 1][k] , dp1[((j & 1) ^ 1)][k - s[j].mon] + s[j].v);
					}
				}
				if(cnt == dp1[n & 1][m])
				{
					ans++;
				}
			}
			printf("%lld\n" , ans);
		}
		return 0;
	}
	else if(C == 18 || C == 16)
	{
		while(T--)
		{
			scanf("%lld %lld" , &n , &m);
			for(int i = 1 ; i <= n ; i++)
			{
				scanf("%lld" , &cost[i]);
			}
			int ans = 1;
			for(int i = 1 ; i <= n ; i++)
			{
				ans = (ans << 1) % M;
			}
			printf("%lld\n" , ans);
		}
		return 0;
	}
	else if(C == 17)
	{
		while(T--)
		{
			scanf("%lld %lld" , &n , &m);
			for(int i = 1 ; i <= n ; i++)
			{
				scanf("%lld" , &cost[i]);
			}
			if(n == 1)
			{
				printf("2\n");
				continue;
			}
			int two = 1;
			for(int i = 1 ; i <= n ; i++)
			{
				two = (two << 1) % M;
			}
			sort(cost + 1 , cost + n + 1);
			if(cost[2] != cost[1] && cost[2] < (cost[1] << 1))
			{
				two--;
			}
			printf("%lld\n" , (two + M) % M);
		}
		return 0;
	}
	else
	{
		while(T--)
		{
			scanf("%lld %lld" , &n , &m);
			for(int i = 1 ; i <= n ; i++)
			{
				scanf("%lld" , &cost[i]);
			}
			if(n == 1)
			{
				printf("2\n");
				continue;
			}
			pw[0] = 1;
			int two = 1;
			for(int i = 1 ; i <= n ; i++)
			{
				two = (two << 1) % M;
				pw[i] = two;
			}
			int ans = pw[n - 1];
			sort(cost + 1 , cost + n + 1);
			if(cost[n] > (cost[n - 1] << 1))
			{
				printf("%lld\n" , pw[n]);
				continue;
			}
			int l = 1;
			int r = n - 1;
			while(l < r)
			{
				int mid = (l + r) >> 1;
				if((cost[mid] << 1) >= cost[n])
				{
					r = mid;
				}
				else
				{
					l = mid + 1;
				}
			}
			if(l < n - 1)
			{
				ans += (pw[n - l] - n + l - 1) * pw[l - 1];
				ans %= M;
			}
			int p = l;
			for(int i = n - 1 ; i >= p ; i--)
			{
				int aim = cost[n] - cost[i];
				if(aim >= cost[p])
				{
					break;
				}
				int l1 = 1;
				int r1 = l - 1;
				while(l1 < r1)
				{
					int mid = (l1 + r1) >> 1;
					if(cost[mid] >= aim)
					{
						r1 = mid;
					}
					else
					{
						l1 = mid + 1;
					}
				}
				ans += pw[l1 - 1] * (pw[p - l1] - 1);
				ans %= M;
			}
			printf("%lld\n" , ans);
		}
		return 0;
	}

	return 0;
}
