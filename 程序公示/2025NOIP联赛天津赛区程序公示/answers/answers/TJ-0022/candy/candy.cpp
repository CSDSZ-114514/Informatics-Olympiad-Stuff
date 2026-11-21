#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
final 1bug expect 90pts
9:40
confirm 12:40
confirm 12:50
*/

const int MAXN = 1e5 + 5 , MAXM = 1e4 + 5;
int n , m;
int minn = 2e9 , mi = 2e9 , mii = 2e9;
int ans;
struct Node{
	int x , y;
	bool choose;
} a[MAXN];

signed main(){
	freopen("candy6.in" , "r" , stdin);
	freopen("candy6.out", "w" , stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin >> n >> m;
	
	if (n == 1){
		int x , y;
		cin >> x >> y;
		ans = (m / (x + y)) << 1;
		m %= x + y;
		if (m >= x) ans ++;
		cout << ans;
		return 0;
	}
	
	for (int i = 1 ; i <= n ; i ++){
		cin >> a[i].x >> a[i].y;
		if (a[i].x < minn) mi = minn , minn = a[i].x;
		else if (minn <= a[i].x && a[i].x < mi) mi = a[i].x;
		mii = min(a[i].x + a[i].y , mii);
	}
//	cout << minn << ' ' << mi << ' ' << mii << endl;
	if (minn + mi >= mii){
		ans = (m / mii) << 1;
		m %= mii;
		if (m >= minn) ans ++;
		cout << ans;
		return 0;
	}
	else{
		sort(a + 1 , a + n + 1 , ([](Node &u , Node &v) -> bool{
			return u.x < v.x;
		}));
		int I;
		for (I = 1 ; I < n && a[I].x + a[I + 1].x <= mii && m >= a[I].x + a[I + 1].x ; I += 2){
			ans += 2;
			m -= a[I].x + a[I + 1].x; 
			a[I].choose = a[I + 1].choose = 1;
		}
		ans += (m / mii) << 1;
		m %= mii;
		for (int i = 1 ; i <= n ; i ++){
			while ((a[i].choose && m >= a[i].y) || (!a[i].choose && m >= a[i].x)){
				if (a[i].choose){
					if (m >= a[i].y) ans ++ , m -= a[i].y , a[i].choose = 0;
				}
				if (!a[i].choose){
					if (m >= a[i].x) ans ++ , m -= a[i].x , a[i].choose = 1;
				}
			}
			
		}
		cout << ans;
		return 0;
	}

	return 0;
}

