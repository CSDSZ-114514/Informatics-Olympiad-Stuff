
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 99;
ll n, m, ans, solvea[N], a[N][2];
bool A = true;

struct node{
	ll cost;
	bool limit;
	bool operator < (const node &b) const{
		if(cost / ((ll)limit + 1) == b.cost / ((ll)b.limit + 1)){
			if(limit == true){
				return true;
			} else{
				return false;
			}
		}
		return cost / ((ll)limit + 1) < b.cost / ((ll)b.limit + 1);
	}
};
vector<node> candys;

int solveA(){
	sort(solvea + 1, solvea + n + 1);
	return (ll)(m / solvea[1]);
}

int main(){
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i][0] >> a[i][1];
		candys.push_back((node){a[i][0] + a[i][1], true});
		candys.push_back((node){a[i][0], false});
		solvea[i] = a[i][0];
		if(a[i][0] != a[i][1]) A = false;
	}
	if(A){
		cout << solveA() << endl;
	} else{
		sort(candys.begin(), candys.end());
		for(int i = 0;i < candys.size();i++){
			//printf("to i = %d, the c = %d, limit = %d, least = %d\n", i, candys[i].cost, candys[i].limit, m);
			if(candys[i].limit == true){
				ll cnt = (ll)(m / candys[i].cost) * 2;
				ans += cnt;
				m -= (ll)(m / candys[i].cost) * candys[i].cost;
				if(cnt >= 1){
					if(m + candys[i - 1].cost >= candys[i].cost){
						ans++;
						m += candys[i - 1].cost - candys[i].cost;
					}
				}
			} else{
				if(m >= candys[i].cost){
					ans++;
					m -= candys[i].cost;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}






/*
4 18
1 1000
1 1000
6 5
10000 10000
*/







