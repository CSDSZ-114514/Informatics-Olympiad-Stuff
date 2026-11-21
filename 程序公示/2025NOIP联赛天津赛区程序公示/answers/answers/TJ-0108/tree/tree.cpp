#include<bits/stdc++.h>
/*
²»Òª¼±£¬¶ÁÌâ.
bie xian xie dai ma!!!
*/
#define pb emplace_back
using namespace std;
inline int read(){
	int res = 0 , t = 1;
	char c = getchar();
	while(c > '9' || c < '0'){
		if(c == '-') t = -t;
		c = getchar();
	}
	while(c <= '9' && c >= '0'){
		res = c - 48 + (res << 1) + (res << 3); 
		c = getchar();
	}
	return res * t;
}
int n , m , k;
const int N = 8004;
int fa[N];
vector<int> G[N];
#define f(i , j , k) for(int i = (j); i <= (k); ++ i)
int col[N] , ans;
unordered_set<int> s[N];
int v[N] , tot;
inline void goo(int x){
	for(auto v :  G[x]){
		goo(v);
	}
	v[++ tot] = x; 
	return ;
}
bool vis[11];
inline int MEX(unordered_set<int> &s){
	memset(vis ,0 , sizeof vis);
	int mx = 0;
	for(auto i : s) vis[i] = 1;
	while(vis[mx]) ++ mx;
	return mx; 
}
inline int query(){
	int res = 0;
	for(auto i = 1; i <= n; ++ i){
		res += MEX(s[i]);
	} 
	return res;
}
inline void dfs(int x){
	if(x == n + 1){
		ans = max(ans , query());
		return ;
	}
	int c = x;
	x = v[x];
	for(auto v : G[x]){
		for(auto k : s[v]) s[x] . insert(k);
	}
	for(int i = 0; i < n; ++ i){
		if(s[x] . find(i) != s[x] . end()) continue;
		s[x] . insert(i);
		dfs(c + 1);
		s[x] . erase(i);
	//	cout << i << ' ';
	} 
	s[x] . clear();
}

inline void solve(){
	n = read() , m = read();
	tot = 0;
	f(i , 1, n) G[i] . clear() , s[i] . clear();
	f(i , 2 , n){
		fa[i] = read();
		G[fa[i]] . pb(i);
	} 
	goo(1);
	ans = 0;
	dfs(1);
	cout << ans << '\n';
	return ;
} 
signed main(){
	freopen("tree.in" , "r" , stdin);
	freopen("tree.out" , "w" , stdout);
	int T; bool op = 0; 
	if(op) T = 1;
	else T = read();
	while(T --) solve();
	return 0;
}
