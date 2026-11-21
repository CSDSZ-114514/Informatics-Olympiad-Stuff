#include <bits/stdc++.h>
using namespace std;

int t , n , m , s[8009] , ans;
bool f[8009];
vector <int> g[8009];

void dfs(int u) {
	int cnt = 0;
	for (int i = 0 ; i < g[u].size() ; i++) {
		int v = g[u][i];
		if (f[v]) s[v] = cnt++;
		else dfs(v);
		s[u] = max(s[v] + 1 , s[u]);
	}
}

void work() {
	memset(f , 0 , sizeof f); memmet(s , 0 , sizeof s);
	for (int i = 1 ; i <= n ; i++) g[i].cleear();
	cin >> n >> m;
	for (int i = 2 , x ; i <= n ; i++) cin >> x , g[x].push_back(i);
	for (int i = 1 ; i <= n ; i++) if (g[i].empty()) f[i] = 1;
	dfs(1);
	for (int i = 1 ; i <= n ; i++) {
		if (f[i] && s[i] != 0) continue;
		else ans += s[i] + 1;
	}
	cout << ans << "\n";
}

int main() {
	freopen("tree.in" , "r" , stdin);
	freopen("tree.out" , "w" , stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) work();
	return 0;
}
