#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e5+1,M = 1e4+1;
int n,m,w[N],dp[M];
struct node{
	int x,y;
}a[N];
inline bool cmp1(const node &x,const node &y){
	if(x.x+x.y!=y.x+y.y){
		return x.x+x.y<y.x+y.y;
	}
}
inline bool cmp2(const node &x,const node &y){
	return x.x<y.x;
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	if(m<=10000){
		for(int i = 1;i<=n;++i){
			cin >> a[i].x >> a[i].y;
			w[i] = a[i].x+a[i].y;
		}
		memset(dp,0xcf,sizeof(dp));
		dp[0] = 0;
		for(int i = 1;i<=n;++i){
			for(int j = w[i];j<=m;++j){
				dp[j] = max(dp[j],dp[j-w[i]]+2);
			}
		}
		int ans = 0;
		for(int i = 1;i<=n;++i){
			for(int j = m;j>=a[i].x;--j){
				dp[j] = max(dp[j],dp[j-a[i].x]+1);
			}
		}
		for(int i = 1;i<=m;++i){
			ans = max(ans,dp[i]);
		}
		cout << ans;
	}else{
		for(int i = 1;i<=n;++i){
			cin >> a[i].x >> a[i].y;
		}
		stable_sort(a+1,a+n+1,cmp1);
		int ans = 0;
		ans+=m/(a[1].x+a[1].y);
		m-=ans*(a[1].x+a[1].y);
		ans<<=1;
		stable_sort(a+1,a+n+1,cmp2);
		for(int i = 1;i<=n;++i){
			if(m>=a[i].x){
				m-=a[i].x;
				++ans;
			}
		}
		cout << ans;
	}
	return 0;
}
