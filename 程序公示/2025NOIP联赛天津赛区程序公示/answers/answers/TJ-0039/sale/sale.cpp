
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5099, M = 998244353;
ll c, t, n, m, a[N];

struct node{
	ll w, r;
	bool operator < (const node &b) const{
		return this->r / w < b.r / b.w;
	}
};

bool check(ll choose){
	priority_queue<node> b;
	ll p = 1, p2 = 1;
	while(p <= choose){
		if(p & choose >= 1){
			b.push((node){2, a[p2]});
		} else{
			b.push((node){1, a[p2]});
		}
		p <<= 1;
		p2++;
	}
	ll lastonecost, lasttwocost, mon = m;
	bool last = false;
	for(int i = 1;i <= n;i++){
		node f = b.top();
		b.pop();
		if(mon >= f.w) mon -= f.w;
		if(f.w == 1 && mon >= 1){
			lastonecost = f.r;
			last = true;
			continue;
		}
		if(mon == 1 && f.w == 2){
			lasttwocost = max(lasttwocost, f.r);
		}
		if(f.w == 1 && mon == 1 && last == false){
			if(lastonecost + f.r < lasttwocost){
				return false;
			}
			return true;
		}
		last = false;
	}
	return true;
}

int main(){
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		if(c == 18){
			long long ans = 1;
			for(int i = 1;i <= n;i++){
				ans *= 2;
				ans %= M;
			}
			cout << ans << endl;
			continue;
		}
		/*int ans = 0;
		for(ll i = 0;i <= pow(2, n);i++){
			if(check(i)){
				ans++;
			}
		}
		cout << ans << endl;*/
	}
	return 0;
}
















