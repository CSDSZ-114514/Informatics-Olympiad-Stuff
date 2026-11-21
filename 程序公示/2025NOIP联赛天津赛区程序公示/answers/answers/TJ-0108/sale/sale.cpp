#include<bits/stdc++.h>
/*
不要急，读题.
bie xian xie dai ma!!!
*/
#define int long long
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
const int P = 998244353; 
const int N = 5e4 + 10;
int pw[N];
bool cmp(pair<int , int> x , pair<int , int> y){
	if(x . first * y . second == y . first * x . second) return x . first > y . first;
	return x . first * y . second > y . first * x . second;
}
/*
0 114
7 2
10 29 38 19 13 30 27
*/
bool flg = 1;
inline void solve(){
	n = read() , m = read();
	vector<int> v;
	for(int i = 1; i <= n; ++ i) v . pb(read());
	v . pb(10000000007ll);
	sort(v . begin() , v . end() , greater<int>() );
	if(v[1] == v[n] || m == 2 * n - 1){
		cout << pw[n] << '\n';
		return ;
	}
	if(m == 2 * n - 2){
		int res = 0;
		for(int i = 1; i <= n; ++ i){
			if(v[i] == v[n]) ++ res;
		}	
		if(res >= 2) {
			cout << pw[n] << '\n';
			return ;
		}
		else{
			if(v[n - 1] >= v[n] * 2) cout << pw[n] << '\n';
			else {
				cout << (pw[n] + P - 1) % P << '\n';
			}
		}
		return ;
	}  
	int lol = -1;
	if(k <= 5 && flg){
		int tttt = 0;
		for(int i = 0; i < (1 << n); ++ i){
			vector<pair<int , int> > ok;
			vector<int> A , B;
			for(int j = 0; j < n; ++ j){
				if(i >> j & 1){
					ok . pb(v[j + 1] , 1) , A . pb(v[j + 1]);
				}
				else ok . pb(v[j + 1] , 2) , B . pb(v[j + 1]);
			}
			int res = 0;
			sort(ok . begin() , ok . end() , cmp);
			int mmmm = m;
			for(auto tmp : ok){
				if(mmmm >= tmp . second){
					mmmm -= tmp . second;
					res += tmp . first;
				}
			}
			sort(A . begin() , A . end() , greater<int>() );
			sort(B . begin() , B . end() , greater<int>() );
			int ans = 0;
			for(int j = 0; j <= A . size(); ++ j){
				if(j > m) continue;
				int tmp = 0;
				for(int k = 0; k < j; ++ k) tmp += A[k];
				for(int k = 0; k < min((int)B . size() , (m - j) / 2); ++ k) tmp += B[k];
				ans = max(ans, tmp);
			}
			if(ans == res){
				++ tttt;
//				if(i & 1) continue;
//				for(auto v  : ok) cout << v . first << ' '<< v . second << '\n';
//				cout << "end\n";
			}
			//cerr << res << '\n'; 
		}
		lol = tttt;
		cout << tttt << '\n';
		return ;
	}
	if(m == 2){
	//	cerr << ">";
		//可以买两颗 1 or 1 * 2
		//type 1: a_1 = 1,
		int res = pw[n - 1]; 
		int pos = n + 1;
		for(int i = 1; i <= n; ++ i){
			if(v[i] <= v[1] / 2){
				pos = i; break;
			}
		}
	//	cout << pos << '\n';
		for(int x = 2; x < pos; ++ x){
			if(v[x] == v[1]){
				res += 1; res %= P;
			}
			for(int y = x + 1; y <= n; ++ y){
				if(v[x] + v[y] >= v[1])
					res = (res + pw[n - y]) % P;
			}
		}
//		for(int x = 1; x <= n; ++ x){
//			for(int y = x + 1; y <= n ; ++ y){
//				if(v[x] + v[y] > v[1]) continue; 
//				res = (res + pw[n - y]) % P; 
//			}  
//		}
		//pos ~ n n - pos + 1
		res += pw[n - pos + 1]; res %= P;
		cout << res << '\n';
	} 
	return ;
}
signed main(){
	freopen("sale.in" , "r" , stdin);
	freopen("sale.out" , "w" , stdout);
	k = read();
	pw[0] = 1;
	for(int i = 1; i <= 50000; ++ i) pw[i] = (pw[i -  1] * 2) % P; 
	int T; bool op = 0;
	if(op) T = 1;
	else T = read();
	while(T --) solve();
	return 0;
}//54292701

