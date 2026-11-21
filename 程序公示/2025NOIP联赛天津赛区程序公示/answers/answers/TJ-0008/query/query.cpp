#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 55000;
ll n, a[N], q, sum[N], k[N];
unsigned ll kk[N]; 

int main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];
	cin >> q;
	while(q--) {
		int L, R; cin >> L >> R;
		for(int i=1; i<=n; i++) {
			k[i] = -LLONG_MAX;
			for(int len=L; len<=R; len++) {
				for(int l=max(1,i-len+1); l<=min((ll)i,n-len+1); l++) {
					int r = l+len-1;
					k[i] = max(k[i], sum[r] - sum[l-1]);
				}
			}
			kk[i] = k[i];
		}
		unsigned ll ans = 0;
		for(int i=1; i<=n; i++) {
			ans ^= i*kk[i];
		} 
		cout << ans << "\n";
	}

	return 0;
}

