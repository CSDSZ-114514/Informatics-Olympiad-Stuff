#include<bits/stdc++.h>
using namespace std;

const int N = 8e3+5, N1 = 400;

int n, m, fa[N], dep[N];
vector<int> son[N];

namespace solve1
{
	int val[N], ans; bool vis[N];
	inline void clear() {
		for(int i = 0; i <= n; i++) {
			vis[i] = false;
		}
	}
	inline void uni(int u)
	{
		vis[val[u]] = true;
		for(auto &v : son[u])
			uni(v);
	}
	inline int cal(int u) 
	{
		int ret = 0;
		for(auto &v : son[u]) {
			ret += cal(v);
		}
		for(auto &v : son[u]) {
			uni(v);
		}
		vis[val[u]] = true;
		for(int i = 0; i < n; i++) {
			if(!vis[i]) {
				ret += i; break;	
			}
		}
		clear();
		return ret;
	}
	inline void getval(int dep)
	{
		if(dep == n+1) {
			int ret = cal(1);
//			if(ret > ans) {
//				printf("ret=%d,val:", ret);
//				for(int i = 1; i <= n; i++) {
//					printf("%d ", val[i]); 
//				}
//				printf("\n");
//			}
			ans = max(ans, ret);
			return;
		}
		for(int i = 0; i < n; i++) {
			val[dep] = i;
			getval(dep+1);
			val[dep] = 0;
		}
	}
}

namespace solve2
{
	int sz[N];
	inline void dfs1(int u)
	{
		sz[u] = 1;
		for(auto &v : son[u]) {
			dfs1(v); sz[u]+=sz[v];
		}
	}
	inline int solve() {
		dfs1(1);
		int ans = 0, mxsz = 0;
		for(auto &v : son[1]) {
			mxsz = max(mxsz, sz[v]);
			ans += sz[v]+(sz[v]>1); 
		}
		ans += mxsz+1;
		return ans;
	}
}

inline void solve()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		son[i] = vector<int> ();
	}
	for(int i = 2; i <= n; i++) {
		scanf("%d", &fa[i]);
		son[fa[i]].push_back(i);
	}
	if(m == 1 && n > 7) {
		printf("%d\n", n+1);
		return;
	}
	else if(m == 2 && n > 7) {
		printf("%d\n", solve2::solve());
		return;
	}
	else {
		solve1::getval(1);
		printf("%d\n", solve1::ans);
		solve1::ans = 0;
		return;
	}
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T = 0; scanf("%d", &T);
	for(int i = 1; i <= T; i++) {
		solve();
	}
	
	
	return 0;
}
