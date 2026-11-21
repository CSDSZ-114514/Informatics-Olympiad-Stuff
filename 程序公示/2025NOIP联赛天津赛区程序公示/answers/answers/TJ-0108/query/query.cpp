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
#define f(i , j , k) for(int i = (j); i <= (k); ++ i)
const int N = 4e5 + 10;
long long s[N];
int a[N];
long long ans[N];
int res1[N];
long long res2[N] , mx[N];
//pair<int , long long > res[N];
inline void solve(){
	n = read();
	f(i , 1 , n) a[i] = read() , s[i] = s[i - 1] + a[i];
	int Q = read();
	while(Q --){
		int l = read() , r = read();
		f(i , 0, n) ans[i] = -1e18 , mx[i] = -1e18;
		unsigned long long tmp = 0;
		for(int len = r; len >= l; -- len){
			int L = 1 , R = 0;
			for(int u = 1; u <= n; ++ u){
				int v = u + len - 1 , val = s[v] - s[u - 1];
				while(L <= R && res1[L] < u)
					 ++ L;
			//	cout << len << ' ' << u << ' ' << val << ' ' << mx[u - 1] << ' '<< mx[u] << '\n'; 
				if(v <= n && val > mx[u]){
					mx[u] = val;
					while(L <= R && val >= res2[R])
						-- R;
					res1[++ R] = v;
					res2[R] = val;
				} 
				if(L <= R)
					ans[u] = max(ans[u] , res2[L]);
			}  
		} 
		f(i , 1, n) tmp ^= (unsigned long long) i * ans[i];
		cout << tmp << '\n';
	}
	/*
	4
2 4 -5 1
3
1 2
3 4
1 4

	*/
	return ;
} 
/*
4
2 4 -5 1
3
1 2
3 4
1 4

*/
signed main(){
	freopen("query.in" , "r" , stdin);
	freopen("query.out" , "w" , stdout);
	int T; bool op = 1; 
	if(op) T = 1;
	else T = read();
	while(T --) solve();
	return 0;
}
