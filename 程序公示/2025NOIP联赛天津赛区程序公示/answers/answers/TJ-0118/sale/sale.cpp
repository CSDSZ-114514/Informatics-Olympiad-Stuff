#include <bits/stdc++.h>
#define int long long
#define mod 998244353 
using namespace std;
int c,t,n,m,a[5001],vis[5001],ans,dp1[31][61],aa1[5001],tt1,aa2[5001],tt2;
struct node{
	int a,b;
}aa[31];
int kasumi(int aa,int b){
	int res = 1;
	while (b){
		if (b & 1){
			res *= aa;
			res %= mod;
		}
		aa *= aa;
		aa %= mod;
		b >>= 1;
	}
	return res;
}
bool cmp(int aa,int bb){
	return aa > bb;
}
bool cmp1(node aa,node bb){
	if (aa.a * bb.b != bb.a * aa.b){
		return aa.a * bb.b > bb.a * aa.b;
	}else{
		return aa.a > bb.a;
	}
}
void dfs(int x){
	if (x == n + 1){
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= m;j++){
				dp1[i][j] = dp1[i - 1][j];
				if (vis[i] <= j){
					dp1[i][j] = max(dp1[i][j],dp1[i - 1][j - vis[i]] + a[i]);
				}
			}
		}
		for (int i = 1;i <= n;i++){
			aa[i].a = a[i];
			aa[i].b = vis[i];
		}
		int cnt = 0,cc = 0;
		sort(aa + 1,aa + n + 1,cmp1);
		for (int i = 1;i <= n;i++){
			if (cc + aa[i].b <= m){
				cc += aa[i].b;
				cnt += aa[i].a;
			}
		}
		int ans1 = 0;
		for (int j = 1;j <= m;j++){
			ans1 = max(ans1,dp1[n][j]);
		}
		if (ans1 == cnt){
			ans++;
			ans %= mod;
		}
		return ;
	}
	vis[x] = 1;
	dfs(x + 1);
	vis[x] = 2;
	dfs(x + 1);
}
int mo(int x){
	return ((x % mod) + mod) % mod;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while (t--){
		scanf("%lld%lld",&n,&m);
		int flag = false;
		for (int i = 1;i <= n;i++){
			scanf("%lld",&a[i]);
			if (a[i] != a[i - 1]){
				flag = true;
			}
		}
		if (!flag){
			printf("%lld\n",kasumi(2,n));
		}else if ((m == 2 * n - 1) || (m == 1)){
			printf("%lld\n",kasumi(2,n));
		}else if (n <= 10){
			sort(a + 1,a + n + 1,cmp);
			ans = 0;
			dfs(1);
			printf("%lld\n",ans);
		}else if ((m == 2) || (m == 2 * n - 2)){
			ans = kasumi(2,n - 1);
			sort(a + 1,a + n + 1,cmp);
			int x = a[1] / 2,cnt1 = 0,cnt2 = 0;
			tt1 = 0;
			tt2 = 0;
			for (int i = 1;i <= n;i++){
				if (a[i] == a[1]){
					cnt2++;
				}
			}
			for (int i = 2;i <= n;i++){
				if (a[i] > x){
					cnt1++;
					aa1[++tt1] = a[i];
				}else{
					aa2[++tt2] = a[i];
				}
			}
			for (int i = 1;i <= tt1;i++){
				int l = 1,r = tt2,anss = tt2 + 1;
				while (l <= r){
					int mid = l + r >> 1;
					if (aa1[i] + aa2[mid] < a[1]){
						anss = mid;
						r = mid - 1;
					}else{
						l = mid + 1;
					}
				}
				ans -= (tt2 - anss + 1);
				ans = mo(ans);
			}
			int ans1 = mo(mo(kasumi(2,cnt1) - 1 - cnt1) * kasumi(2,n - 1 - cnt1));
			int ans2 = mo(mo(kasumi(2,cnt1) - 1) * mo(kasumi(2,n - 1 - cnt1) - 1));
			int ans3 = mo(mo(kasumi(2,cnt1) - 1 - cnt1) * mo(kasumi(2,n - 1 - cnt1) - 1));
			ans += mo(ans1 + ans2 - ans3);
			ans = mo(ans);
			ans += kasumi(2,n - 1 - cnt1);
			ans = mo(ans);
			ans += (cnt2 - 1);
			ans = mo(ans);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
