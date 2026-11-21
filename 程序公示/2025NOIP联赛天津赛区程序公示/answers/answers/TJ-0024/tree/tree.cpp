#include <bits/stdc++.h>
using namespace std;

vector <int> v[20];
vector <int> sons[20];

int num[20];
bool use[20];

int maxn = 0;

void dfs1(int x)
{
	sons[x].push_back(x);
	for(int i = 0 ; i < v[x].size() ; i++)
	{
		dfs1(v[x][i]);
		for(int j = 0 ; j < sons[v[x][i]].size() ; j++)
		{
			sons[x].push_back(sons[v[x][i]][j]); 
		}
	}
	return;
}

void check(int n)
{
	int cnt = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		memset(use , false , sizeof(use));
		for(int j = 0 ; j < sons[i].size() ; j++)
		{
			use[num[sons[i][j]]] = true;
		}
		for(int j = 0 ; j < 8 ; j++)
		{
			if(!use[j])
			{
				cnt += j;
				break;
			}
		}
	}
	maxn = max(maxn , cnt);
	return;
}

void dfs(int x , int n)
{
	if(x == n + 1)
	{
		check(n);
		return;
	}
	for(int i = 0 ; i <= 6 ; i++)
	{
		num[x] = i;
		dfs(x + 1 , n);
	}
	return;
}

int main()
{
	freopen("tree.in" , "r" , stdin);
	freopen("tree.out" , "w" , stdout);
	
	int T;
	scanf("%d" , &T);
	while(T--)
	{
		for(int i = 1 ; i <= 8 ; i++)
		{
			v[i].clear();
			sons[i].clear();
		}
		int n , m;
		scanf("%d %d" , &n , &m);
		int x;
		for(int i = 2 ; i <= n ; i++)
		{
			scanf("%d" , &x);
			v[x].push_back(i);
		}
		dfs1(1);
		dfs(1 , n);
		printf("%d\n" , maxn);
	}

	return 0;
}
