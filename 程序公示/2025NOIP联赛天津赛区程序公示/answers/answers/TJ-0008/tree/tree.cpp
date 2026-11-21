#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 8800;
int t, n, m, a[N]; ll ans = 0, res = 0; 
vector <int> e[N];
set <int> s[N], S;

void solve(int u, int fa) {
	for(auto v : e[u]) {
		if(v == fa) continue; 
		//cout << v << "\n";
		solve(v, u);
		s[u] = s[v];
	}
	s[u].insert(a[u]);
	S.clear(); for(int i=0; i<n; i++) S.insert(i);
	for(auto x : s[u]) if(S.count(x)) S.erase(x);
	res += (*S.begin());
}

void dfs(int cnt) {
	if(cnt > n) {
		for(int i=1; i<=n; i++) {
			s[i].clear();
		}
		res = 0;
		solve(1, 0);
		ans = max(ans, res);
		return;
	}
	for(int i=0; i<n; i++) {
		a[cnt] = i; dfs(cnt+1);
	}
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> t;
	while(t--) {  
		ans = 0;
		cin >> n >> m;
		for(int i=1; i<=n; i++) e[i].clear();
		for(int i=2; i<=n; i++) {
			int p; cin >> p;
			e[p].push_back(i);
		}
		dfs(1);
		cout << ans << "\n"; 
	}
	
	return 0;
}

