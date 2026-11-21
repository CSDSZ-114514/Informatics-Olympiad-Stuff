#include<bits/stdc++.h>
/*
²»Òª¼±£¬¶ÁÌâ.
bie xian xie dai ma!!!
*/
#define pb emplace_back
#define int long long
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
#define f(i , j , k) for(int i = (j); i <= (k); ++ i)
inline void solve(){
	n = read() , m = read();
	vector<int> candy;
	int tt = -1;
	f(i , 1, n){
		int u = read() , v = read();
		if(tt == -1) tt = u + v;
		candy . pb(u); 
		tt = min(tt , u + v);
	}
	assert(tt != -1);
	sort(candy . begin() , candy . end());
	int res = 0 , cnt = 0 , ans = (m / tt) * 2;
	for(auto u : candy){
		++ cnt; res += u; 
		if(m < res) break;
		ans = max(ans , cnt + ((m - res) / tt) * 2);
	}
	cout << ans << '\n';
	return ;
} 
signed main(){
	freopen("candy.in" , "r" , stdin);
	freopen("candy.out" , "w" , stdout);
	int T; bool op = 1; 
	if(op) T = 1;
	else T = read();
	while(T --) solve();
	return 0;
}
