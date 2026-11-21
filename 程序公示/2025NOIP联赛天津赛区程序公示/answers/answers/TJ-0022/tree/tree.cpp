#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

/*
expect 4-8pts
confirm 12:39
*/

const int MAXN = 8005;
int n , H , p[MAXN] , d[MAXN] , son[MAXN];
bool c[MAXN];
vector < vector<int> > t(MAXN);

void f(int u){
	d[u] = d[p[u]] + 1;
	son[u] = 1;
	for (int &to : t[u]){
		f(to);
		son[u] += son[to];
	}
	return ;
}


int v;
int dfs(int u){
//	cout << u << '\t';
	vector <int> seq;
	for (int &to : t[u]) seq.pb(to);
	sort(seq.begin() , seq.end() , ([](int &x , int &y) -> bool{
		return d[x] > d[y] || (d[x] == d[y] && son[x] > son[y]);
	}));
	int ret = 0;
	for (int &to : seq){
		ret += dfs(to);
		c[u] |= c[to]; 
	}
	if (v == 0) c[u] = 1;
	v ++;
	return ret + (c[u] ? v : 0);
}

void solve(){
	d[0] = -1;
	v = 0;
	for (int i = 1 ; i <= n ; i ++){
		c[i] = 0;
		t[i].clear(); 
	}
	cin >> n >> H;
	for (int i = 2 ; i <= n ; i ++){
		cin >> p[i];
		t[p[i]].pb(i);
	}
	f(1);
	cout << dfs(1) << '\n';
	return ;
}

int main(){
	freopen("tree.in" , "r" , stdin);
	freopen("tree.out", "w" , stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while (T --) solve();
	return 0;
}

