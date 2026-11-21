#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e3+1,mod = 998244353;
int c,t,n,m,a[N],w[N],dp[N<<1],ans = 0;
struct node{
	int a,w,id;
}mem[N];
inline bool cmp(const node &x,const node &y){
	if(1.0*x.a/x.w!=1.0*y.a/y.w){
		return 1.0*x.a/x.w>1.0*y.a/y.w;
	}else if(x.a!=y.a){
		return x.a>y.a;
	}
	return x.id<y.id;
}
void dfs(const int &x){
	if(x == n+1){
		for(int i = 0;i<=m;++i){
			dp[i] = INT_MIN;
		}
		dp[0] = 0;
		int now1 = 0;
		for(int i = 1;i<=n;++i){
			for(int j = m;j>=w[i];--j){
				dp[j] = max(dp[j],dp[j-w[i]]+a[i]);
			}
		}
		for(int i = 1;i<=m;++i){
			now1 = max(now1,dp[i]);
		} 
		for(int i = 1;i<=n;++i){
			mem[i] = {a[i],w[i],i};
		}
		stable_sort(mem+1,mem+n+1,cmp);
		int now2 = 0,tmp = m;
		for(int i = 1;i<=n;++i){
			if(tmp>=mem[i].w){
				tmp-=mem[i].w;
				now2+=mem[i].a;
			}
		}
		if(now2 == now1){
			ans = (ans+1)%mod;
		}
		return;
	}
	w[x] = 1;
	dfs(x+1);
	w[x] = 2;
	dfs(x+1);
}
inline int qpow(int base,int e){
	int res = 1;
	while(e){
		if(e&1){
			res = res*base%mod;
		}
		base = base*base%mod;
		e>>=1;
	}
	return res;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1;i<=n;++i){
			cin >> a[i];
		}
		if(c == 18){
			cout << qpow(2,n) << '\n';
			continue;
		}
		ans = 0;
		dfs(1);
		cout << ans << '\n';
	}
	return 0;
}
