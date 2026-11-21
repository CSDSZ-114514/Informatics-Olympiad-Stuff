#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e4+1;
int n,q,a[N],pre[N],k[N];
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i<=n;++i){
		cin >> a[i];
		pre[i] = pre[i-1]+a[i];
	}
	cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;
		for(int i = 1;i<=n;++i){
			k[i] = LLONG_MIN;
		}
		for(int i = 1;i<=n;++i){
			for(int L = max(1ll,i-r+1);L<=i;++L){
				for(int R = i;R<=min(n,i+r-1);++R){
					if(R-L+1<l||R-L+1>r){
						continue;
					}
					k[i] = max(k[i],pre[R]-pre[L-1]);
				}
			}
		}
		unsigned long long ans = 0;
		for(int i = 1;i<=n;++i){
			ans^=i*k[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
