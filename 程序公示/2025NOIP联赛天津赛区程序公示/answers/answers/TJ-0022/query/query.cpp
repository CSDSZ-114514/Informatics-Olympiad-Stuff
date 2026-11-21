#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

/*
confirm 12:49
expect 0-5pts
*/

const int MAXN = 5e4 + 5;
ll n , a[MAXN] , pre[MAXN];
ull X = 1;

ull f(int x){
	if (x >= 0) return x;
	else return X + x + X;
}

ull calc(int L , int R){
	ull ans = 0;
	ll k;
	for (int i = 1 ; i <= n ; i ++){
		k = -1e18;
		for (int len = L ; len <= R ; len ++){
			for (int j = max(i - len + 1 , 1) ; j <= i && j + len - 1 <= n ; j ++){
				k = max(pre[j + len - 1] - pre[j - 1] , k);
			}
		}
		ans ^= f(i * k);
	}
	cout << ans << '\n';
}

int main(){
	freopen("query.in" , "r" , stdin);
	freopen("query.out", "w" , stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for (int i = 1 ; i <= 63 ; i ++){
		X *= 2;
	}
	cin >> n;
	for (int i = 1 ; i <= n ; i ++) cin >> a[i] , pre[i] = pre[i - 1] + a[i];
	int q , L , R;
	cin >> q;
	while (q --){
		cin >> L >> R;
		calc(L , R);
	}
	return 0;
}

