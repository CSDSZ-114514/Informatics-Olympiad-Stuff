#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define pii pair<int,int>
#define mpr make_pair
using namespace std;

/*
12:11
expect 12-16pts
confirm 12:38
confirm 12:52
*/

const int MAXN = 5005 , MOD = 998244353;
int n , m , a[MAXN];

int power(int b , int p){
	int ret = 1;
	while (p){
		if (p & 1) ret = ret * b % MOD;
		b = b * b % MOD;
		p >>= 1;
	}
	return ret;
}

vector < pii > v;
int r;
void dfs(int u , int val , int rest){
	if (u == n + 1){
		r = max(val , r);
		return ;
	}
	dfs(u + 1 , val , rest);
	if (rest >= v[u].second) dfs(u + 1 , val + v[u].first , rest - v[u].second);
	return ;
}

bool calc(int c){
//	if (c == 0 || c + 1 == (1 << n)) return 1;
	v.clear();
//	cout << '\t' << c <<endl;
	for (int i = 0 ; i < n ; i ++) v.pb(mpr(a[i + 1] , ((c & (1 << i)) ? 1 : 0) + 1));
	sort(v.begin() , v.end() , ([](pii &x , pii &y) -> bool{
		return x.first * y.second  > y.first * x.second || (x.first * y.second == y.first * x.second) && x.first > y.first;
	}));
	int re = 0 , rest = m;
	for (auto &i : v){
		if (rest >= i.second) rest -= i.second , re += i.first;
//		cout << i.first << ' ' << i.second << endl;
	}
//	cout << endl;
	r = 0;
	dfs(0 , 0 , m);
//	cout << c << ' ' <<r << ' ' << re << endl;
	return r == re;
}

void solve(){
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++) cin >> a[i];
	int ans = 0;
	for (int c = 0 ; c < (1 << n) ; c ++) ans += calc(c);
	cout << ans << '\n';
}

void solveA(){
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++) cin >> a[i];
	cout << power(2 , n) << '\n';
	return ;
}

signed main(){
	freopen("sale.in" , "r" , stdin);
	freopen("sale.out", "w" , stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c , T;
	cin >> c >> T;
	while (T --){
		if (c >= 18) solveA();
		else solve();
	}
	return 0;
}

