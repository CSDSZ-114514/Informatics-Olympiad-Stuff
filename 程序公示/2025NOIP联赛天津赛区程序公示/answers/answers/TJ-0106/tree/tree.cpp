#include <bits/stdc++.h>
using namespace std;
const int N = 8005;

struct stu
{
	int num,s;
};

int T,n,d,p; 
int t[N];
long long int ans;
vector <stu> v[N]; 

int cmp(stu a,stu b)
{
	return a.s > b.s;
}

void buil(int fa,int u)
{
	if (u != 0)
	{
		if (fa != 0) v[fa][u].s = 1;
		int l = v[u].size();
		if (l == 0) return;	
		for (int i = 0; i<t[u]; i++)
		{
			buil(u,v[u][i].num);
			v[fa][u].s += v[u][i].s;
		}
	}
}

void dfs(int u,int f)
{
	if (!v[u].size()) 
	{
		t[u] = 1;
		return;	
	}
	
	int l = v[u].size();
	sort(v[u].begin(),v[u].end(),cmp);
	for (int i = 0; i<l; i++)
	{
		if (i == 0) 
		{
			dfs(v[u][i].num,f-1);
			t[u] = t[v[u][i].num]+1;
			ans += t[v[u][i].num];
		}
		else
		{
			int cnt = v[u][i].s;
			ans += max(((cnt+1)*cnt)/2,cnt * (f-d+2));
		}
	}
}

int main()
{
	freopen("tree1.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> T;
	while (T--)
	{
		cin >> n >> d;
		for (int i = 2; i<=n; i++)
		{
			cin >> p;
			v[p].push_back({i,0});
		}
		ans = 0;
		buil(0,1);
		ans += t[1];
		dfs(1,d+1);
		cout << ans << endl;
		for (int i = 1; i<= n; i++) 
		{
			int l = v[i].size();
			for (int j = 0; j< l;j++)
			{
				v[i][j].num = 0;
				v[i][j].s = 0;
			}
		}
	}
	
	return 0;
}
